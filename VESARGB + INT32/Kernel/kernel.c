#include "TaraOS.h"

extern int CheckA20(void);
extern void EnableA20(void);
extern void int32(unsigned char intnum, regs16_t *regs);


int kmain()
{
	init_idt();
	SetPITSpeed(100);
	init_DTCursor();
	
	/*
	int y;
    regs16_t regs;
     
    // switch to 320x200x256 graphics mode
    regs.ax = 0x0013;
    int32(0x10, &regs);
     
    // full screen with blue color (1)
    memset((char *)0xA0000, 1, (320*200));
   
	
	*/
	char* str = "Hello, world!\0";
	printf(str,0xffffff,0x000000);
	
	
	
	
	
   for(;;);
}