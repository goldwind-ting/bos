#ifndef __IO_H
#define __IO_H
#include "types.h"

extern u8 inb(u16 port);
extern void outb(u16 port, u8 value);

#endif