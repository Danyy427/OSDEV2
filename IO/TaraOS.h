#ifndef __TARAOS_H
#define __TARAOS_H
    
	//TODO: Add more keys
	unsigned char MapScancodeToAscii(unsigned Scancode)
	{
		unsigned char ret = 0;
		if(Scancode == 0x2) ret = '1'; 
		else if(Scancode == 0x3) ret = '2'; 
		else if(Scancode == 0x4) ret = '3'; 
		else if(Scancode == 0x5) ret = '4'; 
		else if(Scancode == 0x6) ret = '5'; 
		else if(Scancode == 0x7) ret = '6'; 
		else if(Scancode == 0x8) ret = '7'; 
		else if(Scancode == 0x9) ret = '8'; 
		else if(Scancode == 0xA) ret = '9'; 
		else if(Scancode == 0xB) ret = '0'; 
		else if(Scancode == 0xC) ret = '-'; 
		else if(Scancode == 0xD) ret = '='; 
		else if(Scancode == 0xF) ret = '	'; 
		else if(Scancode == 0x10) ret = 'q'; 
		else if(Scancode == 0x11) ret = 'w'; 
		else if(Scancode == 0x12) ret = 'e'; 
		else if(Scancode == 0x13) ret = 'r'; 
		else if(Scancode == 0x14) ret = 't'; 
		else if(Scancode == 0x15) ret = 'y'; 
		else if(Scancode == 0x16) ret = 'u'; 
		else if(Scancode == 0x17) ret = 'i'; 
		else if(Scancode == 0x18) ret = 'o'; 
		else if(Scancode == 0x19) ret = 'p'; 
		else if(Scancode == 0x1A) ret = '['; 
		else if(Scancode == 0x1B) ret = ']'; 
		else if(Scancode == 0x1C) ret = '\n'; 
		else if(Scancode == 0x1E) ret = 'a'; 
		else if(Scancode == 0x1F) ret = 's'; 
		else if(Scancode == 0x20) ret = 'd'; 
		else if(Scancode == 0x21) ret = 'f'; 
		else if(Scancode == 0x22) ret = 'g'; 
		else if(Scancode == 0x23) ret = 'h'; 
		else if(Scancode == 0x24) ret = 'j'; 
		else if(Scancode == 0x25) ret = 'k'; 
		else if(Scancode == 0x26) ret = 'l'; 
		else if(Scancode == 0x27) ret = ';'; 
		else if(Scancode == 0x28) ret = '\''; 
		else if(Scancode == 0x29) ret = '`'; 
		else if(Scancode == 0x2C) ret = 'z'; 
		else if(Scancode == 0x2D) ret = 'x'; 
		else if(Scancode == 0x2E) ret = 'c'; 
		else if(Scancode == 0x2F) ret = 'v'; 
		else if(Scancode == 0x30) ret = 'b'; 
		else if(Scancode == 0x31) ret = 'n'; 
		else if(Scancode == 0x32) ret = 'm'; 
		else if(Scancode == 0x33) ret = ','; 
		else if(Scancode == 0x34) ret = '.'; 
		else if(Scancode == 0x34) ret = '/'; 
		else if(Scancode == 0x39) ret = ' '; 
		return ret;
	}
	//Video
	//Definitions of Video constants
	
	#define __VIDMEM__ 0xb8000
	#define __MAXROW__ 25
	#define __MAXCOL__ 80
	#define __REG_SCREEN_CTRL__ 0x3D4
	#define __REG_SCREEN_DATA__ 0x3D5
	#define __DEFAULT_WOB__ 0x0f
	
	//Keyboard
	//Definition of Keyboard Driver constants
	
	#define __STATUS_PORT__ 0x64
	#define __DATA_PORT__ 0x60
	
	
	int strlen(char *s)
	{
		char *p = s;
		while (*p != '\0')
			++p;
		return p - s; //use ptrdiff_t or size_t?
	}

	void print_ch(char chr, unsigned attribute, int X, int Y)
	{
		int offset = __VIDMEM__ + ((Y * __MAXCOL__ + X)*2);
		char* vm = __VIDMEM__;
		
		*((char*) offset ) = chr;
			
		*((char*) offset+1 ) = attribute;
		
	}
	
	
	
#endif

