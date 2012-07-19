#ifndef GRAPHICS_H
#define GRAPHICS_H

#include<SDL.h>
#include<string>
#include<SDL_image.h>

using namespace std;

class Graphics
{
    public:
        Graphics();

        SDL_Surface *Image;
        SDL_Rect Rect, Dest;

        void LoadImage(string filename);
        void Clip(int x, int y, int w, int h);
        void Move(int x, int y);

        virtual ~Graphics();

    protected:

    private:
};

#endif // GRAPHICS_H
