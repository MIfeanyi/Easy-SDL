#include <SDL.h>

#include "Window.hpp"
#include "Font.hpp"
#include "String.hpp"
#include "Audio.hpp"
#include "System.hpp"
#include "Game.hpp"



int main ( int argc, char* args[])
{
    SDL_Init( SDL_INIT_EVERYTHING );
    TTF_Init();

    int STATE = 0; //used to manage state
    bool Running = true;

    Window App;

    Audio Sound;
    App.CreateWindow(640,480,"SDL Pong",false);

    while(Running)
    {

        switch(STATE)
        {
        case 0:
            STATE = UpdateMenu(App);
            break;
        case 1:
            STATE = UpdateGame(App);
            break;
        case 2:
            break;
        default:
            return STATE; // probably an error code
            break;
        };
    }



    SDL_Quit();
    return 0;
}
