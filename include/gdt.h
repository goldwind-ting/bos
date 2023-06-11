#ifndef __GDT_H
#define __GDT_H

#include "types.h"

typedef struct GDTEntry
{
    u16 limit_low;
    u32 base_low : 24;
    u8 type : 4;
    u8 segment : 1;
    u8 DPL : 2;          // descriptor privilege level
    u8 present : 1;
    u8 limit_high : 4;
    u8 available : 1;
    u8 long_mode : 1;    // 1: 64bits
    u8 big : 1;          // 1: 32bits; 0: 16bits
    u8 granularity : 1;  // 1: 4KB; 0: 1 bit; 
    u8 base_high;
} GDTEntry;


typedef struct GDTSelector
{
    u8 RPL : 3;
    u8 TI : 1;
    u16 IX : 13;
} GDTSelector;

void gdt_init();
void gdt_entry_init(GDTEntry *desc, int32 base, int32 limit, u8 type, u8 dpl);

#endif