#include <SDL.h>
 
#include "Window.hpp"
#include "Audio.hpp"
#include "System.hpp"


#include "Game.hpp"

int main ( int argc, char* args[])
{
    SDL_Init( SDL_INIT_EVERYTHING );

    int STATE = 1; //used to manage state
    bool Running = true;

    Window App;
    Audio Sound;
    App.CreateWindow(640,480,"SDL Pong",false);
    SDL_Delay(3000);

    while(Running)
    {

        switch(STATE)
        {
        case 0:
            STATE = UpdateMenu();
            break;
        case 1:
            STATE = UpdateGame(App);
            break;
        case 2:
            STATE = UpdateWinLose();
            break;
        default:
            return STATE; // probably an error code
            break;
        };
    }



    SDL_Quit();
    return 0;
}
