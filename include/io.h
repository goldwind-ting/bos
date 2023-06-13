#ifndef __IO_H
#define __IO_H
#include "types.h"

extern u16 inb_(u16 port);
extern void outb_(u16 port, u8 value);

#endif