#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#include "electric_common.h"

size_t
WritePageToBuffer(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t newsize = size * nmemb;
    Buffer *buff = (Buffer*)userp;

    buff->data = (char*)realloc(buff->data, buff->size + newsize + 1);

    if (buff->data == NULL) {
        fprintf(stderr, "WritePageToBuffer() failed to allocate memory\n");
        newsize = 0;
    } else {
        memcpy(&(buff->data[buff->size]), contents, newsize);
        buff->size = newsize;
        buff->data[buff->size-1] = '\0';
    }

    return newsize;
}