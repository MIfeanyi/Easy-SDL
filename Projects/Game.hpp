#ifndef GAME
#define GAME


#include"Ball.hpp"
#include"Paddle.hpp"
#include"Collision.hpp"

int UpdateGame(Window &App)
{
    App.FPS =60;

    //maybe i need a reference to the window
    Uint8 *Key;
    SDL_Event Event;
    bool Running = true;
    bool Start   = false;

    //Game Items
    Ball GameBall;
    Paddle PlayerPaddle;
    Paddle AIPaddle;

    GameBall.ResetBall(App);
    PlayerPaddle.Reset(App, true);
    AIPaddle.Reset(App, false);

    PlayerPaddle.Speed = 5;

    GameBall.BallHeight = 3;
    GameBall.Direction = 4;

    //Images
    cout<<"Loading Images"<<endl;
    GameBall.Gfx.LoadImage("Data/Ball.png");
    PlayerPaddle.Gfx.LoadImage("Data/Paddle.png");
    AIPaddle.Gfx.LoadImage("Data/Paddle.png");
    //Music
    //
    //Sound Chunks
    //

    while(Running)
    {
        Key = SDL_GetKeyState(NULL);

        while( SDL_PollEvent(&Event) )
        {
            if(Event.type == SDL_QUIT)
            {
                Running = false;

            }
        }

        if(!Start)
        {
            /* check if space is hit & display "hit space to begin" */
            //cout<<"waiting for space press"<<endl;
            if( Key[SDLK_SPACE] )
            {
                Start = true;
                GameBall.Start();

            }
        }
        else
        {

            //if(!ball.IsMoving)
            //Ball.MoveRandom(); //start ball
            //allow objects to update
            //check for collisions
            //Draw
            //Check if game is over
            GameBall.Move();

            //move ball
            if( Key[SDLK_UP] )
            {
                PlayerPaddle.Move(true);
            }
            else if( Key[SDLK_DOWN] )
            {
                PlayerPaddle.Move(false);
            }

            //AIPaddle.Move(GameBall);

            //Collision stuff goes here

            //Draw


        }


        App.Clear();

        App.Draw(AIPaddle.Gfx);
        App.Draw(PlayerPaddle.Gfx);
        App.Draw(GameBall.Gfx);

        App.LimitFramerate();
        App.Flip();

    }

    return 10;
}

void CheckCollision()
{
    Collision Col;
}

int UpdateMenu()
{
    return 0;
}

int UpdateWinLose()
{
    return 0;
}

#endif // GAME
