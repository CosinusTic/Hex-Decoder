#include "../include/io.h"

#include <stdio.h>
#include <stdlib.h>

char *loadf(char *path)
{
    FILE *f = fopen(path, "rb");

    if (!f)
        return NULL;

    fseek(f, 0, SEEK_END);
    long length = ftell(f);

    rewind(f);
    char *buf = malloc(length + 1);

    if (!buf)
    {
        fclose(f);
        return NULL;
    }

    fread(buf, 1, length, f);
    buf[length] = '\0';
    fclose(f);
    return buf;
}
