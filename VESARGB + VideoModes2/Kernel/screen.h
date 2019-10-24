#ifndef __SCREEN_H__
#define __SCREEN_H__

	static void putpixel(unsigned char* screen, int x,int y, int color) {
		unsigned where = x*3 + y*3840;
		screen[where] = color & 255;              // BLUE
		screen[where + 1] = (color >> 8) & 255;   // GREEN
		screen[where + 2] = (color >> 16) & 255;  // RED          // RED
	}

    void fill_rect(unsigned char* screen, int fromx, int tox, int fromy,int toy,int color)
    {
		/*
        unsigned char* fb = screen;
        for(int i = fromy; i < toy ; i++ )
        {
            for(int j = fromx; j < tox*3 ; j)
            {
                putpixel(fb,j,i,color);
            }

        }*/
		 unsigned char* fb = screen + fromx*3 + fromy*2400;
		 
		 for(int j = 0; j < toy; j++)
		 {
			 for(int i = 0 ; i < tox*3 ; i++ )
			 {
				fb[i*3] =  color & 255;              // BLUE
				fb[i*3 + 1] =(color >> 8) & 255;               // GREEN
				fb[i*3 + 2] = (color >> 16) & 255;  
				 
			 }
			 fb += 3840;
			 
		 }
		 
		
    }


#endif