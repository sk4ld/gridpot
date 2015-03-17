/*
 *  gebrick.c
 *
 * - Emulate the GE Brick Merging Unit 
 * - Interact with Gridlabd to obtain Electric Grid Info
 */

/* C Library Includes */
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>

/* libiec61850 Includes */
#include <curl/curl.h>
#include <iec61850_server.h>
#include <hal_thread.h>

/* local includes */
#include "electric_common.h"
#include "static_model_switch_control.h"
/*#include "static_model_ge_brick.h"*/

 extern IedModel iedModel;

 static int running = 0;
 
void
catchSigInt(int signalId)
{
   running = 0;
}

int
triggerGridlabSwitchStatus(char *newval)
{
    int ret = 0;
    CURL    *curl;
    Buffer  buff;
    char    url[200];

    memset(&buff, 0, sizeof(Buffer));
    memset(url, 0, 100);

    curl = curl_easy_init();
    if (curl) {
        CURLcode res;

        snprintf(url, 200, "%s=%s","http://localhost:6267/switch_671-692/status",
            newval);

        printf("%s\n", url);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        /*curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);*/
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "GE Brick/1.0");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WritePageToBuffer);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buff);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", 
            curl_easy_strerror(res));
        } else {
            fprintf(stdout, "%lu bytes retrieved\n", (long)buff.size);
            fprintf(stdout, "%s\n", buff.data);
        }

        if (buff.data != NULL) {
            free(buff.data);
            buff.data = NULL;
            buff.size = 0;
       }
    }

    /* Clean up curl, close connection */
    curl_easy_cleanup(curl);

    return ret;
}

void
controlHandler(void *parameter, MmsValue *value)
{
    int val = false;

    if (parameter == IEDMODEL_GenericIO_GGIO1_SPCSO1) {
        if (MmsValue_getType(value) == MMS_BOOLEAN) {
            val = MmsValue_getBoolean(value);

            if(val == 0)
                triggerGridlabSwitchStatus("OPEN");
            else
                triggerGridlabSwitchStatus("CLOSED2");
        }
    }
}

void
connectionHandler (IedServer self, ClientConnection connection, bool connected, void* parameter)
{
    if (connected)
        printf("[*] IED client connected successfully\n");
    else
        printf("[*] IED client disconnected successfully\n");
}

int
main(int argc, char** argv)
{
    IedServer iedServer = NULL;

    /* Server is now running */
    signal(SIGINT, catchSigInt);
    running = 1;

    /* initiate server */
    iedServer = IedServer_create(&iedModel);

    /* Start MMS server on port 102 */
    IedServer_start(iedServer, 102);

    if (!IedServer_isRunning(iedServer)) {
        fprintf(stdout, "Failed to start server...\n");
        IedServer_destroy(iedServer);
        exit(1);
    }

    /* Enable GOOSE publishing */
    IedServer_enableGoosePublishing(iedServer);

    /* Setup control handlers */
    IedServer_setControlHandler(iedServer, IEDMODEL_GenericIO_GGIO1_SPCSO1,
        (ControlHandler) controlHandler, IEDMODEL_GenericIO_GGIO1_SPCSO1);

    /* Setup connection handler */
    IedServer_setConnectionIndicationHandler(iedServer, 
        (IedConnectionIndicationHandler) connectionHandler, NULL);

    /* Setup GOOSE control block */

    while(running == 1) {

        IedServer_lockDataModel(iedServer);
        
        /* IED server logic */

        IedServer_unlockDataModel(iedServer);

        Thread_sleep(100);
    }

    /* Stop servers, close ports and free resources */
    IedServer_stop(iedServer);
    IedServer_destroy(iedServer);

    return 0;
 }