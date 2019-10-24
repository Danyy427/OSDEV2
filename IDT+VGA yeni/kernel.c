#include "TaraOS.h"

int kmain()
{
    init_idt();
	SetPITSpeed(100);
	
	init_DTCursor();
	printf("hello worldaaaaaaaaaaaaaa!!! \0", 0x0f, 0x0);
	
	wait_key();
	
  	printf("key pressed!!\0", 0x0f, 0x0);
	wait_key();
    printf("key pressed!!\0", 0x0f, 0x0);
	
	TSleep(100);
	printf("1 second has passed \0", 0x0f, 0x0);
    TSleep(100);
   
    while(1);
}