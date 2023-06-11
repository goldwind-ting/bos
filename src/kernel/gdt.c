#include "constant.h"
#include "debug.h"
#include "gdt.h"
#include "str.h"
#include "types.h"

GDTEntry gdt[GDT_SIZE];

void gdt_entry_init(GDTEntry *desc, int32 base, int32 limit, u8 type, u8 dpl)
{
    if (limit <= 65536)
    {
        desc->granularity = 0;
    }
    else
    {
        if ((limit & 0xFFF) != 0xFFF)
        {
            limit = (limit >> 12) - 1;
        }
        else
        {
            limit = limit >> 12;
        }
        desc->granularity = 1;
    }

    desc->limit_low = limit & 0xFFFF;
    desc->limit_high = (limit >> 16) & 0xF;
    desc->base_low = base & 0xFFFFFF;
    desc->base_high = (base >> 24) & 0xFF;
    desc->segment = 1;
    desc->big = 1;
    desc->available = 0;
    desc->long_mode = 0;
    desc->DPL = dpl;
    desc->present = 1;
    desc->type = type;
}

void gdt_init()
{
    printf("\ninitialize gdt\n");
    memset(gdt, 0, sizeof(gdt));
    GDTEntry *unused = gdt + UNUSED_GDT_ENTRY;
    gdt_entry_init(unused, 0, 0, 0, 0);

    GDTEntry *kernel_code = gdt + KERNEL_CODE_IX;
    gdt_entry_init(kernel_code, 0, 0xFFFFFFFF, 0, 10);

    GDTEntry *kernel_data = gdt + KERNEL_DATA_IX;
    gdt_entry_init(kernel_data, 0, 0xFFFFFFFF, 0, 2);

    GDTEntry *user_code = gdt + USER_CODE_IX;
    gdt_entry_init(user_code, 0, 0xFFFFFFFF, 3, 10);

    GDTEntry *user_data = gdt + USER_DATA_IX;
    gdt_entry_init(user_data, 0, 0xFFFFFFFF, 3, 2);

    uintptr_t gdt_ptr[2];
    gdt_ptr[1] = (uintptr_t)gdt;
    gdt_ptr[0] = (uintptr_t)sizeof(gdt) << 16;
    asm volatile("lgdt (%0)"
                 :
                 : "p"(((u8 *)gdt_ptr) + 2));
}
