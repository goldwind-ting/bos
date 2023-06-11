#include "debug.h"
#include "gdt.h"
#include "types.h"



void kernelMain()
{
    gdt_init();
    printf("Hello World! --goldwin-ting");
}