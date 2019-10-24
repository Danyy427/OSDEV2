OS:
	nasm -fbin Bootloader/bootload.asm -o Bin/bootload.bin
	nasm -fbin Bootloader/diskpad.asm -o Bin/diskpad.bin
	nasm Bootloader/A20Check.asm -f elf -o Bin/a20.o

	i386-elf-gcc -mno-ms-bitfields -nostdlib -lgcc -fno-PIC -m32 -ffreestanding -c Kernel/kernel.c -o Bin/kernel.o
	nasm Kernel/kernel_entry.asm -f elf -o Bin/k_entry.o

	i386-elf-ld -T link.ld -o Bin/kernel.tmp Bin/k_entry.o Bin/a20.o Bin/kernel.o
	i386-elf-objcopy -O binary Bin/kernel.tmp Bin/kernel.bin

	cat Bin/bootload.bin  Bin/kernel.bin  Bin/diskpad.bin > os-image.bin


	qemu-system-i386 -monitor stdio os-image.bin

clean:
	del *.o
	del *.temp
	del *.bin
