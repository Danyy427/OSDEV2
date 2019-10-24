#ifndef __SCREEN_H__
#define __SCREEN_H__


    void putpixel(unsigned char* screen, int x,int y, int color) {
        unsigned char* fb = screen;
        unsigned int offset = y * 1280 + x;
        fb[offset] = color;
    }

    void draw_line(unsigned char* screen, int fromx, int tox, int y,int color)
    {
        unsigned char* fb = screen;
        unsigned int offset = y * 1280 + fromx;

        for(int i = 0;i < tox; i++)
        {
            fb[offset+i] = color;
        }
    }

    void fill_rect(unsigned char* screen, int fromx, int tox, int fromy,int toy,int color)
    {
        unsigned char* fb = screen;
        unsigned int start_offset = fromy * 1280 + fromx;
        unsigned int end_offset = toy * 1280 + tox;

        for(int i = fromy; i < toy ; i++ )
        {
            for(int j = fromx; j < tox ; j++)
            {
                putpixel(fb,j,i,color);
            }

        }
    }


#endif