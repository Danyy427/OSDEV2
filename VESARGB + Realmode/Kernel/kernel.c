#include "TaraOS.h"

extern vbe_info_structure;

int kmain()
{
	
	
    init_idt();
	SetPITSpeed(100);
	
	init_DTCursor();
	
	char* str = "Hello, world!\0";
	printf(str,0xffffff,0x000000);
	
	
	
    while(1);
}