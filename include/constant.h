#ifndef __CONSTANT_H
#define __CONSTANT_H

#define GDT_SIZE 128

#define UNUSED_GDT_ENTRY 0
#define KERNEL_CODE_IX 1
#define KERNEL_DATA_IX 2
#define KERNEL_TSS_IX 3

#define USER_CODE_IX 4
#define USER_DATA_IX 5

#endif