[bits 32]

section .text
global inb
global outb

inb:
    push ebp
    mov ebp, esp
    xor eax, eax
    mov edx, [ebp + 8]
    in al, dx
    nop
    nop
    leave
    ret

outb:
    push ebp
    mov ebp, esp
    xor eax, eax
    mov edx, [ebp + 8]
    mov eax, [ebp + 12]
    out dx, al
    nop
    nop
    leave
    ret

section .note.GNU-stack
