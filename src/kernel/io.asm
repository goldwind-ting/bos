[bits 32]

section .text
global inb_
global outb_

inb_:
    push ebp
    mov ebp, esp
    xor eax, eax
    mov edx, [ebp + 8]
    in al, dx
    nop
    nop
    leave
    ret

outb_:
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
