#include "Window.hpp"

Window::Window()
{
    //ctor
}
Window::Window(int WindowWidth, int WindowHeight, string WindowTitle, bool Full)
{
    IsOpen      = true;
    Screen      = NULL;
    Width       = WindowWidth;
    Height      = WindowHeight;
    Title       = WindowTitle;
    Fullscreen  = Full;

    SDL_WM_SetCaption(Title.c_str(),NULL);

    if(Fullscreen)
    {
        Screen  = SDL_SetVideoMode( Width, Height, 32, SDL_DOUBLEBUF|SDL_FULLSCREEN );
    }
    else
    {
        Screen  = SDL_SetVideoMode( Width, Height, 32, SDL_SWSURFACE );
    }
}

Window::~Window()
{
    //dtor
}

void Window::CreateWindow(int WindowWidth, int WindowHeight, string WindowTitle, bool Full)
{
    IsOpen      = true;
    Screen      = NULL;
    Width       = WindowWidth;
    Height      = WindowHeight;
    Title       = WindowTitle;
    Fullscreen  = Full;

    SDL_WM_SetCaption(Title.c_str(),NULL);

    if(Fullscreen)
    {
        Screen  = SDL_SetVideoMode( Width, Height, 32, SDL_DOUBLEBUF|SDL_FULLSCREEN );
    }
    else
    {
        Screen  = SDL_SetVideoMode( Width, Height, 32, SDL_SWSURFACE );
    }
}

void Window::Draw(Graphics &Gfx)
{
    SDL_BlitSurface(Gfx.Image, &Gfx.Rect,Screen, &Gfx.Dest);
}
