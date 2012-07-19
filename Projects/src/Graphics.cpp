#include "Graphics.hpp"

Graphics::Graphics()
{
    //ctor
}

Graphics::~Graphics()
{
    //dtor
}

void Graphics::LoadImage(string filename)
{
    SDL_Surface* Load = NULL;
    Image = NULL;

    Load = IMG_Load( filename.c_str() );

    if(Load != NULL)
    {
        Image = SDL_DisplayFormat( Load );
        SDL_FreeSurface( Load );
    }
    else
    {
        //printf("Image loading failed for: %s", filename.c_str() );
        cout<<"Image loading failed:"<< filename <<endl;
    }
}

void Graphics::Clip(int x, int y, int w, int h)
{
    Rect.x = x;
    Rect.y = y;
    Rect.w = w;
    Rect.h = h;
}

void Graphics::Move(int x, int y)
{
    Dest.x = x;
    Dest.y = y;
}
