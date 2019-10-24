#include "IO.h"
#include "TaraOS.h"
#include "screen.h"

unsigned CURSOR_X = 0;
unsigned CURSOR_Y = 0;

int kmain()
{
	char* vm = 0xA0000;
	unsigned char ch;
	unsigned _ch;
	set_background(vm,0xf);
	while(1)
	{
		 ch = inb(0x60);
		 _ch = MapScancodeToAscii(ch);
		  
		  if(_ch == 'a')
		  {
			putpixel(vm,CURSOR_X+2,CURSOR_Y+3,4);
			putpixel(vm,CURSOR_X+3,CURSOR_Y+3,4);
			
			putpixel(vm,CURSOR_X+1,CURSOR_Y+4,4);
			putpixel(vm,CURSOR_X+4,CURSOR_Y+4,4);
			
			putpixel(vm,CURSOR_X+1,CURSOR_Y+5,4);
			putpixel(vm,CURSOR_X+4,CURSOR_Y+5,4);
			
			putpixel(vm,CURSOR_X+2,CURSOR_Y+6,4);
			putpixel(vm,CURSOR_X+3,CURSOR_Y+6,4);
			putpixel(vm,CURSOR_X+5,CURSOR_Y+6,4);
			
			_ch = '\0';
			ch = 0x0;
			
			
			
			if(CURSOR_X >= 310){CURSOR_X=0; CURSOR_Y += 5;}
			else CURSOR_X +=6;
			
			for(int i = 0; i < 30000000; i++)
			{}
			
		  }
		  if(_ch == 'b')
		  {
			//set_background(vm,0xf);
			putpixel(vm,CURSOR_X+1,CURSOR_Y+1,4);
			putpixel(vm,CURSOR_X+1,CURSOR_Y+2,4);
			
			putpixel(vm,CURSOR_X+1,CURSOR_Y+3,4);
			putpixel(vm,CURSOR_X+2,CURSOR_Y+3,4);
			putpixel(vm,CURSOR_X+3,CURSOR_Y+3,4);
			
			putpixel(vm,CURSOR_X+1,CURSOR_Y+4,4);
			putpixel(vm,CURSOR_X+4,CURSOR_Y+4,4);
			
			putpixel(vm,CURSOR_X+1,CURSOR_Y+5,4);
			putpixel(vm,CURSOR_X+4,CURSOR_Y+5,4);
			
			putpixel(vm,CURSOR_X+1,CURSOR_Y+6,4);
			putpixel(vm,CURSOR_X+2,CURSOR_Y+6,4);
			putpixel(vm,CURSOR_X+3,CURSOR_Y+6,4);
			
			
			
			_ch = '\0';
			ch = 0x0;
			
			
			
			if(CURSOR_X >= 310){CURSOR_X=0; CURSOR_Y += 5;}
			else CURSOR_X +=6;
			
			for(int i = 0; i < 30000000; i++)
			{}
			
		  }
		  
		  
		  
	}
	return 0;
}


