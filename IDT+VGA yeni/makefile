OS:
	nasm -fbin bootload.asm -o bootload.bin
	nasm -fbin diskpad.asm -o diskpad.bin
	
	gcc -ffreestanding -c kernel.c -o kernel.o
	nasm kernel_entry.asm -f elf -o k_entry.o
	ld -T link.ld -o kernel.tmp k_entry.o kernel.o
	objcopy -O binary kernel.tmp kernel.bin

	copy /b bootload.bin+kernel.bin+diskpad.bin os-image.bin
	
	qemu-system-i386 -monitor stdio os-image.bin

clean:
	del *.o
	del *.temp
	del *.bin
