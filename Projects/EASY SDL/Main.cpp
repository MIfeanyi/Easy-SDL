#include <SDL.h>

#include "Window.hpp"
#include "Audio.hpp"

int main ( int argc, char* args[])
{
    SDL_Init( SDL_INIT_EVERYTHING );

    Window App;
    Audio Sound;
    App.CreateWindow(640,480,"Easy SDL",false);
    SDL_Delay(3000);




    SDL_Quit();
    return 0;
}
