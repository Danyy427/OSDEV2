#include "TaraOS.h"


int kmain(struct VbeInfoBlock *vbeinfo)
{


    init_idt();
	SetPITSpeed(100);

	init_DTCursor();

  uint32_t physical_address = (vbeinfo->video_modes_segment << 4) +
                              vbeinfo->video_modes_offset;

  uint16_t *videoListPointer = (uint16_t *)physical_address;
  char buf[9];

  while(*videoListPointer != 0xffff) {
      itoa(*videoListPointer, buf, 16);
      printf(buf, 0xffffffff, 0x00000000);
      printf(" ", 0xffffffff, 0x00000000);
      videoListPointer++;
  }




    while(1);
}
