#ifndef GAME
#define GAME


#include"Ball.hpp"
#include"Paddle.hpp"
#include"Collision.hpp"

bool CheckCollision(Ball ball, Paddle paddle)
{
    if( ball.Gfx.Dest.x + ball.Gfx.Dest.w  > paddle.Gfx.Dest.x &&
        ball.Gfx.Dest.x < paddle.Gfx.Dest.x + paddle.Gfx.Dest.w &&
        ball.Gfx.Dest.y + ball.Gfx.Dest.h > paddle.Gfx.Dest.y &&
        ball.Gfx.Dest.y < paddle.Gfx.Dest.y + paddle.Gfx.Dest.h
       )
       {
           return true;
       }
       else
       {
           return false;
       }


}

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
        //Collision between Paddle & ball
        if( CheckCollision(GameBall,AIPaddle) )
        {
            cout<<"Collision"<<endl;
            GameBall.Bounce();
        }
        if( CheckCollision(GameBall,PlayerPaddle) )
        {
            GameBall.Bounce();
            cout<<"Collision"<<endl;
        }

        //bounces ball
        if(GameBall.Gfx.Dest.x > App.Width)
        {
            GameBall.Bounce();
        }
        if(GameBall.Gfx.Dest.x < 0)
        {
            GameBall.Bounce();
        }
        if(GameBall.Gfx.Dest.y + 32 > App.Height)
        {
            GameBall.Bounce(1);
        }
        if(GameBall.Gfx.Dest.y < 0)
        {
            GameBall.Bounce(1);
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



int UpdateMenu()
{
    return 0;
}

int UpdateWinLose()
{
    return 0;
}

#endif // GAME
