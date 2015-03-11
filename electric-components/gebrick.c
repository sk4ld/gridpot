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
#include "static_model_ge_brick.h"

 extern IedModel iedModel;

 static int running = 0;
 
 void
 catchSigInt(int signalId)
 {
    running = 0;
 }

 int
 main(int argc, char** argv)
 {
    CURL *curl;
    Buffer buff;

    /* Initiate curl */
    curl = curl_easy_init();
    memset(&buff, 0, sizeof(Buffer));

    if (curl) {
        CURLcode res;

        curl_easy_setopt(curl, CURLOPT_URL,
            "http://localhost:6267/switch_671-692/power_in");
        /*curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);*/
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "GE Brick/1.0");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WritePageToBuffer);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buff);

        /* initiate server */
        IedServer iedServer = IedServer_create(&iedModel);

        /* Start MMS server on port 102 */
        IedServer_start(iedServer, 102);

        if (!IedServer_isRunning(iedServer)) {
            fprintf(stdout, "Failed to start server...\n");
            IedServer_destroy(iedServer);
            exit(-1);
        }

        /* Server is now running */
        signal(SIGINT, catchSigInt);
        running = 1;

        /* Enable GOOSE publishing */
        IedServer_enableGoosePublishing(iedServer);

        while(running == 1) {

            IedServer_lockDataModel(iedServer);
            
            res = curl_easy_perform(curl);
            if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", 
                curl_easy_strerror(res));
            } else {
                fprintf(stdout, "%lu bytes retrieved\n", (long)buff.size);
                fprintf(stdout, "%s\n", buff.data);
            }

            IedServer_unlockDataModel(iedServer);

            Thread_sleep(100);
        }

        /* Stop servers, close ports and free resources */
        IedServer_stop(iedServer);
        IedServer_destroy(iedServer);
    }
    /* Clean up curl, close connection */
    curl_easy_cleanup(curl);

    if (buff.data != NULL) {
        free(buff.data);
        buff.data = NULL;
        buff.size = 0;
    }

    return 0;
 }