OS:
	nasm -fbin Bootloader/bootload.asm -o Bin/bootload.bin
	nasm -fbin Bootloader/diskpad.asm -o Bin/diskpad.bin
	nasm Bootloader/A20Check.asm -f elf -o Bin/a20.o
	
	gcc -mno-ms-bitfields -fno-PIC -m32 -ffreestanding -c Kernel/kernel.c -o Bin/kernel.o
	nasm Kernel/kernel_entry.asm -f elf -o Bin/k_entry.o
	ld -T link.ld -o Bin/kernel.tmp Bin/k_entry.o Bin/a20.o Bin/kernel.o
	objcopy -O binary Bin/kernel.tmp Bin/kernel.bin

	copy /b "Bin\bootload.bin" + "Bin\kernel.bin" + "Bin\a20.bin" + "Bin\diskpad.bin" /b "os-image.bin"
	
	
	qemu-system-i386 -monitor stdio os-image.bin

clean:
	del *.o
	del *.temp
	del *.bin
