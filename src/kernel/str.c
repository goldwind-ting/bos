#include "types.h"
#include "str.h"

void *memset(void *dest, int32 ch, u32 count)
{
    char *ptr = dest;
    while (count--)
    {
        *ptr++ = ch;
    }
    return dest;
}