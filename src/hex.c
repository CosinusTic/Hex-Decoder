#include "../include/hex.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

char *eat(char *cursor, size_t length)
{
    printf("-- Reversed line --\n");

    char ascii[5]; // 4 bytes + null terminator
    ascii[4] = '\0';

    printf("Hex:    ");
    for (int i = length - 2, j = 0; i >= 0; i -= 2, j++)
    {
        char high = cursor[i];
        char low = cursor[i + 1];

        printf("%c%c ", high, low);

        unsigned char byte = hexpair_to_byte(high, low);
        ascii[j] = isprint(byte) ? byte : '.';
    }

    printf("| ASCII: %s\n", ascii);

    return cursor + length;
}

unsigned char hexpair_to_byte(char high, char low)
{
    int value = 0;

    if (high >= '0' && high <= '9')
        value += (high - '0') << 4;
    else if (high >= 'a' && high <= 'f')
        value += (high - 'a' + 10) << 4;
    else if (high >= 'A' && high <= 'F')
        value += (high - 'A' + 10) << 4;

    if (low >= '0' && low <= '9')
        value += (low - '0');
    else if (low >= 'a' && low <= 'f')
        value += (low - 'a' + 10);
    else if (low >= 'A' && low <= 'F')
        value += (low - 'A' + 10);

    return (unsigned char)value;
}

void revdump(char *content)
{
    size_t length = 8;

    while (*content != '\0')
    {
        if (*content == '\n')
        {
            content++;
            continue;
        }

        char *start = content;
        content = eat(start, length);

        // Skip to next line
        while (*content != '\n' && *content != '\0')
            content++;
        if (*content == '\n')
            content++;
    }
}
