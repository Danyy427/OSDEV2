#include "TaraOS.h"


int kmain(struct VbeInfoBlock vbeinfo)
{


  init_idt();
	SetPITSpeed(100);

	init_DTCursor();






    while(1);
}
