#include "IO.h"
#include "screen.h"

#ifndef __TARAOS_H
#define __TARAOS_H
    
	#define NULL 0
	//TODO: Add more keys
	unsigned char MapScancodeToAscii(unsigned Scancode)
	{
		unsigned char ScancodeTabel[] = {
			'\0',		// hata durumu için '' yani 0x00
			'\0',		//
			'1',
			'2',
			'3',
			'4',
			'5',
			'6',
			'7',
			'8',
			'9',
			'0',
			'-',
			'=',
			'	',
			'q',
			'w',
			'e',
			'r',
			't',
			'y',
			'u',
			'i',
			'o',
			'p',
			'[',
			']',
			'\n',
			'a',
			's',
			'd',
			'f',
			'g',
			'h',
			'j',
			'k',
			'l',
			',',
			'\\',
			'`',
			'z',
			'x',
			'c',
			'v',
			'b',
			'n',
			'm',
			',',
			'.',
			'/',
			' '
		};
		
		unsigned char ret = ScancodeTabel[Scancode];
		
		// anladığım kadarıyla klavye 0x2'den daha düşük değer döndürmüyor ama
		// hata olması ve bir şekilde döndürmesi duruma karşı buraya bir hata yakalama kodu koymalıyız
		if(ret == 0) {/* TODO: ADD ERROR - HANDLE CODE */}
		
		return ret;
	}
	//Video
	//Definitions of Video constants
	
	#define __VIDMEM__ 0xA000
	#define __DEFAULT_WOB__ 0x0f
	
	//Keyboard
	//Definition of Keyboard Driver constants
	
	#define __STATUS_PORT__ 0x64
	#define __DATA_PORT__ 0x60
	
	
	void* memset(void* ptr, int value, int num) 
	{ 
	   unsigned char* ptr_byte = (unsigned char*)ptr;

	   for (int i = 0; i < num; ptr_byte[i] = (unsigned char)value, i++);   
	   return ptr;
	}
	
	int strlen(char *s)
	{
		char *p = s;
		while (*p != '\0')
			++p;
		return p - s; 
	}
	
	int strcmp(char string1[], char string2[] )
	{
		for (int i = 0; ; i++)
		{
			if (string1[i] != string2[i])
			{
				return string1[i] < string2[i] ? -1 : 1;
			}
			if (string1[i] == '\0')
			{
				return 0;
			}
		}
	}
	
	void set_background(unsigned char* screen,int color)
	{
		unsigned char* vm = screen;
		fill_rect((int)vm,0,320,0,200,color);	
	}
	
	
	
	//IDT///////////////////////////////////////////
	struct idt
	{
		short limit;
		unsigned int base;
	}__attribute__ ((packed));
	struct idt_entry
	{
		short base_low;
		short select;
		char always0;
		char flags;
		short base_high;
	}__attribute__ ((packed));
	struct idt Tidt;
	struct idt_entry _idt_entries[256];
	#define IDTBASE    0x00000000
	#define IDTSIZE 0xFF
	
	void init_idt_entry(int num, unsigned int offset, unsigned short select, 
		unsigned short flags)
		{
			_idt_entries[num].base_low = (offset & 0xffff);
			_idt_entries[num].base_high =  (offset & 0xffff0000) >> 16;
			_idt_entries[num].always0 = 0;
			_idt_entries[num].flags = flags;
			_idt_entries[num].select = select;
			 return;
		}
	void isr_common_handler()
	{
		
		asm(".intel_syntax noprefix;"
			"sti;"
			"iret;"
			".att_syntax prefix;"
			);
	}
	void isr0()
	{
		asm(".intel_syntax noprefix;"
			""
			"cli;"
			".att_syntax prefix;"
			);
		
		set_background((unsigned char*)0xA0000, 0x20);
		
		
		
		isr_common_handler();
	}
	void isr1()
	{
		asm(".intel_syntax noprefix;"
			"cli;"
			".att_syntax prefix;"
			);
		
		set_background((unsigned char*)0xA0000, 0x21);
		
		isr_common_handler();
	}
	void isr2()
	{
		asm(".intel_syntax noprefix;"
			"cli;"
			".att_syntax prefix;"
			);
		
		set_background((unsigned char*)0xA0000, 0x22);
		
		isr_common_handler();
	}
	void isr3()
	{
		asm(".intel_syntax noprefix;"
			"cli;"
			".att_syntax prefix;"
			);
		
		set_background((unsigned char*)0xA0000, 0x23);
		
		isr_common_handler();
	}
	void isr4()
	{
		asm(".intel_syntax noprefix;"
			"cli;"
			".att_syntax prefix;"
			);
		
		set_background((unsigned char*)0xA0000, 0x24);
		
		isr_common_handler();
	}
	void isr5()
	{
		asm(".intel_syntax noprefix;"
			"cli;"
			".att_syntax prefix;"
			);
		
		set_background((unsigned char*)0xA0000, 0x25);
		
		isr_common_handler();
	}
	void isr6()
	{
		asm(".intel_syntax noprefix;"
			"cli;"
			".att_syntax prefix;"
			);
		
		set_background((unsigned char*)0xA0000, 0x26);
		
		isr_common_handler();
	}
	void isr7()
	{
		asm(".intel_syntax noprefix;"
			"cli;"
			".att_syntax prefix;"
			);
		
		set_background((unsigned char*)0xA0000, 0x27);
		
		isr_common_handler();
	}
	void isr8()
	{
		asm(".intel_syntax noprefix;"
			"cli;"
			".att_syntax prefix;"
			);
		
		set_background((unsigned char*)0xA0000, 0x28);
		
		isr_common_handler();
	}
	void isr9()
	{
		asm(".intel_syntax noprefix;"
			"cli;"
			".att_syntax prefix;"
			);
		
		set_background((unsigned char*)0xA0000, 0x29);
		
		isr_common_handler();
	}
	void isr10()
	{
		asm(".intel_syntax noprefix;"
			"cli;"
			".att_syntax prefix;"
			);
		
		set_background((unsigned char*)0xA0000, 0x2a);
		
		isr_common_handler();
	}
	void isr11()
	{
		asm(".intel_syntax noprefix;"
			"cli;"
			".att_syntax prefix;"
			);
		
		set_background((unsigned char*)0xA0000, 0x2b);
		
		isr_common_handler();
	}
	void isr12()
	{
		asm(".intel_syntax noprefix;"
			"cli;"
			".att_syntax prefix;"
			);
		
		set_background((unsigned char*)0xA0000, 0x2c);
		
		isr_common_handler();
	}
	void isr13()
	{
		asm(".intel_syntax noprefix;"
			"cli;"
			".att_syntax prefix;"
			);
		
		
	
		
		set_background((unsigned char*)0xA0000, 0x2d);
		asm(".intel_syntax noprefix;"
			"sti;"
			"iret;"
			".att_syntax prefix;"
			);
	}
	void isr14()
	{
		asm(".intel_syntax noprefix;"
			"cli;"
			".att_syntax prefix;"
			);
		
		set_background((unsigned char*)0xA0000, 0x2e);
		
		isr_common_handler();
	}
	void isr15()
	{
		asm(".intel_syntax noprefix;"
			"cli;"
			".att_syntax prefix;"
			);
		
		set_background((unsigned char*)0xA0000, 0x2f);
		
		isr_common_handler();
		
	}
	
	
	
	void idt_flush(int offset)
	{
		asm volatile(
		".intel_syntax noprefix;"
		"mov eax, [esp+4]  ;" 
		"lidt [eax]        ;"
		"ret;"
		".att_syntax prefix;"
		);
	}
	
	void init_pic()
	{
		
		outb(0x20,0x11);
		outb(0xA0,0x11);
		
		outb(0x21, 0x20);
        outb(0xA1, 40);
		
        outb(0x21, 0x04);
        outb(0xA1, 0x02);
		
        outb(0x21, 0x01);
        outb(0xA1, 0x01);
		
        outb(0x21, 0x0);
        outb(0xA1, 0x0);
		
		
	}
	
	
	void init_idt()
	{
		init_pic();
		Tidt.limit = 8 * 256;
		Tidt.base  = (unsigned)&_idt_entries; // değişecek
		
		
		memset(&_idt_entries, 0, 8*256); // değişecek
		
		for(int i = 0; i < 256 ; i++){
			init_idt_entry(i,(unsigned)&isr0,0x08, 0x8E); // bütün hepsini aynı anda yapıyor bu
		}
		
		init_idt_entry(0,(unsigned)&isr0,0x08, 0x8E); 
		init_idt_entry(1,(unsigned)&isr1,0x08, 0x8E); 
		init_idt_entry(2,(unsigned)&isr2,0x08, 0x8E); 
		init_idt_entry(3,(unsigned)&isr3,0x08, 0x8E); 
		init_idt_entry(4,(unsigned)&isr4,0x08, 0x8E); 
		init_idt_entry(5,(unsigned)&isr5,0x08, 0x8E); 
		init_idt_entry(6,(unsigned)&isr6,0x08, 0x8E); 
		init_idt_entry(7,(unsigned)&isr7,0x08, 0x8E); 
		init_idt_entry(8,(unsigned)&isr8,0x08, 0x8E); 
		init_idt_entry(9,(unsigned)&isr9,0x08, 0x8E); 
		init_idt_entry(10,(unsigned)&isr10,0x08, 0x8E); 
		init_idt_entry(11,(unsigned)&isr11,0x08, 0x8E); 
		init_idt_entry(12,(unsigned)&isr12,0x08, 0x8E); 
		init_idt_entry(13,(unsigned)&isr13,0x08, 0x8E); 
		init_idt_entry(14,(unsigned)&isr14,0x08, 0x8E); 
		init_idt_entry(15,(unsigned)&isr15,0x08, 0x8E); 

		
		
		idt_flush((int)&Tidt);
		
		
		asm volatile(".intel_syntax noprefix;"
			"sti;"
			".att_syntax prefix;"
			);
	}
	
	
#endif

