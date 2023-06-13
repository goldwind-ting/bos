#include "debug.h"
#include "gdt.h"
#include "io.h"
#include "types.h"

void to_string(u16 integer){
    while (integer != 0) {
        u16 mod = integer % 10;
        switch (mod)
        {
        case 0:
            printf("0");
            break;
        case 1:
            printf("1");
            break;
        case 2:
            printf("2");
            break;
        case 3:
            printf("3");
            break;
        case 4:
            printf("4");
            break;
        case 5:
            printf("5");
            break;
        case 6:
            printf("6");
            break;
        case 7:
            printf("7");
            break;
        case 8:
            printf("8");
            break;
        case 9:
            printf("9");
            break;
        default:
            break;
        }
        integer = integer / 10;
    }
    printf("\n");
}

void kernelMain()
{
    gdt_init();
    outb_(0x35, 30);
    u16 v = inb_(0x35);
    to_string(v);
    printf("Hello World! --goldwin-ting");
}