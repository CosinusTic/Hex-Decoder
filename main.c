#include <ctype.h> // for isprint
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "include/hex.h"
#include "include/io.h"

#define BUFFER 1024

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 1;

    char *content = loadf(argv[1]);

    if (!content)
    {
        fprintf(stderr, "Failed to load file.\n");
        return 1;
    }

    printf("File content: \n%s", content);
    puts("\n--------------------");
    revdump(content);
    free(content);

    return 0;
}
