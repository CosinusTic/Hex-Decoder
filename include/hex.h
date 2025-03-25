#ifndef HEX_H
#define HEX_H

#include <stdlib.h>

char *eat(char *cursor, size_t length);
unsigned char hexpair_to_byte(char high, char low);
void revdump(char *content);

#endif /* !HEX_H */
