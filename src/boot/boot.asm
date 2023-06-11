extern kernelMain
global start

section .text
bits 32    ; By default, GRUB sets us to 32-bit mode.
start:
    mov esp, kernel_stack
    call kernelMain

_stop:
    cli
    hlt
    jmp _stop

section .bss
bits 32
stack: resb 2*1024*1024
kernel_stack:
section .note.GNU-stack