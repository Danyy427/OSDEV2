#include "TaraOS.h"

extern int CheckA20(void);
extern void EnableA20(void);

int kmain()
{
    init_idt();
	SetPITSpeed(100);
	
	init_DTCursor();
	
	if(CheckA20() == 1)
	{
		printf("A20 is enabled already \0", 0x0f, 0x0);
	}
	else
	{
		printf("A20 is not enabled \0", 0x0f, 0x0);
		
	}
	
	
    while(1);
}