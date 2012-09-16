#include"System.hpp"

System::System()
{
    //ctor
}

void System::Init()
{

}

//SDL_keysym.h
int System::BindKey()
{
    SDL_Event Event;
    bool Running = true;
    SDL_Delay(500); // add some delay so the last key hit doesnt repeat itself
    while(Running)
    {
        while( SDL_PollEvent(&Event) )
        {
            switch (Event.type)
            {
            case SDL_KEYDOWN:
                cout<<"Keybound to: "<< Event.key.keysym.sym <<endl;
                return Event.key.keysym.sym;
                break;
            };
        }
    }
}

System::~System()
{
    //dtor
}
