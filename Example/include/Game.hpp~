#ifndef GAME
#define GAME


#include"Ball.hpp"
#include"Paddle.hpp"
#include"Collision.hpp"


int UpdateMenu();
int UpdateWinLose(bool Win, Window &App);
int UpdateGame(Window &App);
bool CheckCollision(Ball ball, Paddle paddle);

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

int UpdateMenu(Window &App)
{
    App.FPS =60;
    Uint8 *Key;
    SDL_Event Event;
    bool Running = true;
    Font DefaultFont;
    DefaultFont.font =  TTF_OpenFont("Data/PressStart2P.ttf",8);

    String Menu;
    Menu.ChangeColor(255,255,255);
    Menu.ChangeText("Press SPACE to Start the game. ESC to exit.");

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

        if( Key[SDLK_SPACE] )
        {
            Running = false;
            return 1;
        }
        if( Key[SDLK_ESCAPE])
        {
            return 20;
        }

        App.DrawText(Menu, DefaultFont, 10, 30);

        App.LimitFramerate();
        App.Flip();
        App.RenderText();

        App.Clear();
    }

    return 20;
}


int UpdateWinLose(bool Win, Window &App)
{
    Uint8 *Key;
    SDL_Event Event;
    bool Running = true;
    Font DefaultFont;
    DefaultFont.font =  TTF_OpenFont("Data/PressStart2P.ttf",8);

    String WinLose;
    String Menu; //displays the exit menu for the player
    Menu.ChangeColor(255,255,255);
    WinLose.ChangeColor(255,255,255);

    Menu.ChangeText("Press ESC to exit. SPACE to play again.");
    if(Win)
    {
        WinLose.ChangeText("You Win!");
    }
    else
    {
        WinLose.ChangeText("AI Wins! Try again next time.");
    }

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

        if( Key[SDLK_SPACE] )
        {
            return 1;
        }
        if( Key[SDLK_ESCAPE])
        {
            return 15;
        }

        App.DrawText(WinLose, DefaultFont,  10, 10);
        App.DrawText(Menu, DefaultFont, 10, 30);

        App.LimitFramerate();
        App.Flip();
        App.RenderText();

        App.Clear();
    }
    return 15;
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
    AIPaddle.Speed     = 5;

    GameBall.BallHeight = 3;
    GameBall.Direction = 4;

    int PlayerScore = 0;
    int AIScore = 0;

    //Strings & Font
    String AIString;
    String PlayerString;
    String StartString;

    AIString.ChangeColor(255,255,255);
    PlayerString.ChangeColor(255,255,255);
    StartString.ChangeColor(255,255,255);

    AIString.ChangeText(0);
    PlayerString.ChangeText(0);
    StartString.ChangeText("Press SPACE to start.");

    Font DefaultFont;
    DefaultFont.font =  TTF_OpenFont("Data/PressStart2P.ttf",18);

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
            GameBall.ResetBall(App);
            PlayerPaddle.Reset(App, true);
            AIPaddle.Reset(App, false);
            App.DrawText(StartString, DefaultFont,  100, 200);
            if( Key[SDLK_SPACE] )
            {
                Start = true;
                GameBall.Start();

            }
        }
        else
        {
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

            AIPaddle.Move(GameBall);
        }
        //Collision between Paddle & ball
        if( CheckCollision(GameBall,AIPaddle) )
        {
            //cout<<"Collision"<<endl;
            GameBall.Bounce();
            //GameBall.Random();
        }
        if( CheckCollision(GameBall,PlayerPaddle) )
        {
            //cout<<"Collision"<<endl;
            GameBall.Bounce();
            //GameBall.Random();

        }

        //bounces ball
        if(GameBall.Gfx.Dest.x + 32 > App.Width)
        {
            GameBall.Bounce();
            AIScore += 15;
            AIString.ChangeText(AIScore);
            Start = false;
        }
        if(GameBall.Gfx.Dest.x < 0)
        {
            GameBall.Bounce();
            PlayerScore += 15;
            PlayerString.ChangeText(PlayerScore);
            Start = false;
        }
        if(GameBall.Gfx.Dest.y + 32 > App.Height)
        {
            GameBall.Bounce(1);
        }
        if(GameBall.Gfx.Dest.y < 0)
        {
            GameBall.Bounce(1);
        }


        App.DrawText(AIString, DefaultFont,  100, 20);
        App.DrawText(PlayerString, DefaultFont,  400, 20);

        App.Draw(AIPaddle.Gfx);
        App.Draw(PlayerPaddle.Gfx);
        App.Draw(GameBall.Gfx);

        App.LimitFramerate();
        App.Flip();
        App.RenderText();

        App.Clear();

        if(PlayerScore > 45)
        {
            return UpdateWinLose(true,App);
        }
        if(AIScore > 45)
        {
            return UpdateWinLose(false,App);
        }


    }



    return 10;
}






#endif // GAME
