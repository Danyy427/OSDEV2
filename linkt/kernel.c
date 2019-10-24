#include "types.h"

int kmain()
{
	
	
	char* vm = 0xb8000;
	*vm = 'T';
		
		char* vm1 = 0xb8000+2;
	*vm1 = 'A';
	char* vm2 = 0xb8000+4;
	*vm2 = 'R';
	char* vm3 = 0xb8000+6;
	*vm3	= 'A';
	char* vm4 = 0xb8000+8;
	*vm4 = ' ';
	char* vm5 = 0xb8000+10;
	*vm5 = 'O';
	char* vm6 = 0xb8000+12;
	*vm6 = 'S';
	char* vm7 = 0xb8000+14;
	*vm7 = '.';
	char* vm8 = 0xb8000+16;
	*vm8 = '.';
	char* vm9 = 0xb8000+18;
	*vm9 = '.';
}


