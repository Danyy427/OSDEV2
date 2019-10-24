#include "IO.h"
#include "TaraOS.h"
#include "screen.h"

unsigned X = 0;
unsigned Y = 0;

int kmain()
{
	char* vm = __VIDMEM__;
	unsigned char SC ;
	unsigned char ch;
	char* _ch = "abc\0";
	while (1)
	{
		update_cursor(X,Y);
		SC = inb(__DATA_PORT__);
		ch = MapScancodeToAscii(SC);
		
		if(ch != 0 )
		{
			
			if(ch == 'w')
			{
				
				print_ch('w',__DEFAULT_WOB__,1,1);
			}
			
			*((char*) vm + get_cursor() ) =ch;
			
		}
		
		
	}
	

}


