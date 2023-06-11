vpath %.c src/kernel
vpath %.asm src/boot

kernel := build/kernel.bin
iso := build/hello.iso

gccparams = -m32 -Iinclude -nostdlib -fno-builtin -fno-exceptions -fno-leading-underscore -Wno-write-strings


linker_script := linker.ld
grub_cfg := src/boot/grub.cfg
c_source_files := kernel.c debug.c gdt.c str.c
assembly_source_files := boot.asm multiboot_header.asm
assembly_object_files := $(patsubst %.asm, build/%.o, $(assembly_source_files))
c_object_files := $(patsubst %.c, build/%.o, $(c_source_files))

.PHONY: all clean iso kernel qemu qemu-gdb
all: $(kernel)

clean:
	- @rm -fr build
	- @rm -f serial.log *.o
	- @rm -fr build/isofiles

qemu: $(iso)
	qemu-system-x86_64 -cdrom $(iso) -vga std -s -serial file:serial.log

qemu-gdb: $(iso)
	qemu-system-x86_64 -cdrom $(iso) -vga std -s -serial file:serial.log -S

iso: $(iso)
	@echo "Done"

$(iso): $(kernel) $(grub_cfg)
	mkdir -p build/isofiles/boot/grub
	cp $(kernel) build/isofiles/boot/kernel.bin
	cp $(grub_cfg) build/isofiles/boot/grub
	grub2-mkrescue -o $(iso) build/isofiles #2> /dev/null

$(kernel): $(assembly_object_files) $(c_object_files) $(linker_script)
	ld -m elf_i386 -n -T $(linker_script) -o $(kernel) $(assembly_object_files) $(c_object_files)

# comple c files
build/%.o: %.c
	gcc $(gccparams) -c -o $@ $<

# compile assembly files
build/%.o: %.asm
	@mkdir -p $(shell dirname $@)
	nasm -felf32 $< -o $@

