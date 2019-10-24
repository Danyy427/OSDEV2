#include "IO.h"
#include "TaraOS.h"
#include "screen.h"



extern "C" int kmain()
{
	int* vm = (int*) 0xA0000;
	*vm = 4;
	
	
	while(1)     // main kernel loop
	{
		  
	}
	
	return 0;
	
}


