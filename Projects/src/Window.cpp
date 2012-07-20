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
    Tick        = SDL_GetTicks();
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

void Window::LimitFramerate()
{
    //Tick = SDL_GetTicks();
    cout<< SDL_GetTicks() <<endl;

    //1000 = 1.000sec
    if( SDL_GetTicks() - Tick < 1000 / FPS )
    {
        cout<<"Delay: "<< SDL_GetTicks() <<endl;
        cout<<"Ticks: "<< Tick<<endl;
        SDL_Delay( (int)((1000 / FPS) - (SDL_GetTicks() - Tick ) ) );
    }
}
void Window::CreateWindow(int WindowWidth, int WindowHeight, string WindowTitle, bool Full)
{
    IsOpen      = true;
    Screen      = NULL;
    Width       = WindowWidth;
    Height      = WindowHeight;
    Title       = WindowTitle;
    Fullscreen  = Full;
    Tick        = SDL_GetTicks();

    SDL_WM_SetCaption(Title.c_str(),NULL);

    if(Fullscreen)
    {
        Screen  = SDL_SetVideoMode( Width, Height, 32, SDL_DOUBLEBUF|SDL_FULLSCREEN );
    }
    else
    {
        Screen  = SDL_SetVideoMode( Width, Height, 32, SDL_DOUBLEBUF | SDL_HWSURFACE );
    }
}

void Window::Draw(Graphics &Gfx)
{
    SDL_BlitSurface(Gfx.Image,/* &Gfx.Rect */ NULL,Screen, &Gfx.Dest);
}

void Window::Clear()
{
    SDL_FillRect(Screen, 0, SDL_MapRGB(Screen->format, 0, 0, 0));
}

void Window::Flip()
{
    if(SDL_Flip(Screen) == -1 )
    {
        cout<<"SDL_FLIP Error!"<<endl;
    }
    Tick = SDL_GetTicks();
}
