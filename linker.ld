ENTRY(start)

SECTIONS {
    . = 0x100000; /* Tells GRUB to load the kernel starting at the 1MiB mark */

    sboot = .;
    .boot :
    {
        *(.multiboot_header)
    }
    . = ALIGN(4K);
    eboot = .;

    stext = .;
    .text :
    {
        *(.text)
    }
    . = ALIGN(4K);
    etext = .;

    srodata = .;
    .rodata : {
        *(.rodata .rodata.*)
        *(.srodata .srodata.*)
    }
    . = ALIGN(4K);
    erodata = .;

    sdata = .;
    .data : {
        *(.data .data.*)
        *(.sdata .sdata.*)
    }
    . = ALIGN(4K);
    edata = .;

    .bss : {
        *(.bss.stack)
        sbss = .;
        *(.bss .bss.*)
        *(.sbss .sbss.*)
    }
    . = ALIGN(4K);
    ebss = .;
}