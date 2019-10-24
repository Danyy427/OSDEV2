
OS:
	nasm -fbin Bootloader/bootload.asm -o Build/bootload.bin
	nasm -fbin Bootloader/bootload.asm -o bootload.bin
	g++ -ffreestanding -c Kernel/kernel.cpp -o Build/kernel.o
	nasm Kernel/kernel_entry.asm -f elf -o Build/k_entry.o
	ld -T NUL -o Build/kernel.tmp -Ttext 0x1000 Build/k_entry.o Build/kernel.o
	objcopy -O binary -j .text  Build/kernel.tmp Build/kernel.bin
	objcopy -O binary -j .text  Build/kernel.tmp kernel.bin
	merge.bat
	del kernel.bin
	del bootload.bin
	qemu-system-i386 os-image.bin
clean:
	del *.o
	