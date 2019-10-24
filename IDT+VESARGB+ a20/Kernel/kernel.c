#include "TaraOS.h"

extern int CheckA20(void);
extern void EnableA20(void);

int kmain()
{
    init_idt();
	SetPITSpeed(100);
	
	init_DTCursor();
	
	
	char* str = "Hello, world!\0";
	printf(str,0xffffff,0x000000);
	
	
	
    while(1);
}