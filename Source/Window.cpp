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
    //cout<< SDL_GetTicks() <<endl;

    //1000 = 1.000sec
    if( SDL_GetTicks() - Tick < 1000 / FPS )
    {
        //cout<<"Delay: "<< SDL_GetTicks() <<endl;
        //cout<<"Ticks: "<< Tick<<endl;
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

void Window::DrawText(String &DrawString, Font &font, int x, int y)
{
    SDL_Rect Rect;
    Rect.x = x;
    Rect.y = y;

    SDL_Surface *TextSurface;
    TextSurface = TTF_RenderText_Solid(font.font, DrawString.Text.c_str(), DrawString.TextColor );

    SDL_BlitSurface(TextSurface,NULL,Screen, &Rect);
    SDL_FreeSurface(TextSurface);

}

void Window::RenderText()
{
    SDL_BlitSurface(Text,NULL,Screen, NULL);
}

void Window::Clear()
{
    SDL_FillRect(Screen, 0, SDL_MapRGB(Screen->format, 0, 0, 0));
}

void Window::Clear(int R, int G, int B)
{
    SDL_FillRect(Screen, 0, SDL_MapRGB(Screen->format, R, G, B));
}

void Window::Flip()
{
    if(SDL_Flip(Screen) == -1 )
    {
        cout<<"SDL_FLIP Error!"<<endl;
    }
    Tick = SDL_GetTicks();
}
