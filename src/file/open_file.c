#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "file.h"

FILE*
open_file(const char* name)
{
    FILE* file_d = fopen(name, "rb");
    if (file_d == NULL) { fprintf(stderr, "neko: %s: %s\n", name, strerror(errno)); return NULL;}
    return file_d;
}

