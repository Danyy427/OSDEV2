#ifndef __SCREEN_H__
#define __SCREEN_H__
	#include "TaraOS.h"
	#include "IO.h"
	
	void enable_cursor(unsigned cursor_start, unsigned cursor_end)
	{
		outb(0x3D4, 0x0A);
		outb(0x3D5, (inb(0x3D5) & 0xC0) | cursor_start);
	 
		outb(0x3D4, 0x0B);
		outb(0x3D5, (inb(0x3E0) & 0xE0) | cursor_end);
	}
	
	void disable_cursor()
	{
		outb(0x3D4, 0x0A);
		outb(0x3D5, 0x20);
	}
	
	int get_cursor () {

		outb( 0x3D4 , 14);
		int offset = inb( 0x3D5 ) << 8;
		outb( 0x3D4 , 15);
		offset += inb( 0x3D5 );
		return offset *2;
	}
		
	
	void update_cursor(int x, int y)
	{
		unsigned pos = y * 25 + x;
	 
		outb(0x3D4, 0x0F);
		outb(0x3D5, (unsigned) (pos & 0xFF));
		outb(0x3D4, 0x0E);
		outb(0x3D5, (unsigned) ((pos >> 8) & 0xFF));
	}
#endif

