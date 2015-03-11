#ifndef __ELEC_COMMON_H__
#define __ELEC_COMMON_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

typedef struct BufferStruct {
    char *data;
    size_t size;
} Buffer;

size_t
WritePageToBuffer(void *contents, size_t size, size_t nmemb, void *userp);
#endif