OS:
	nasm -fbin bootload.asm -o bootload.bin
	gcc -ffreestanding -c kernel.c -o kernel.o
	nasm kernel_entry.asm -f elf -o k_entry.o
	ld -T NUL -o kernel.tmp -Ttext 0x1000 k_entry.o kernel.o
	objcopy -O binary -j .text  kernel.tmp kernel.bin
	copy /b bootload.bin+kernel.bin os-image.bin 
	qemu-system-i386 -monitor stdio os-image.bin 
clean:
	del *.o
	del *.temp
	del *.bin