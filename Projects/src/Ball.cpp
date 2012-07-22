#include "Ball.hpp"

Ball::Ball()
{
    //ctor
    //Speed = 0;
    Gfx.Dest.h = 32;
    Gfx.Dest.w = 32;
}

void Ball::Bounce()
{
    Speedx *= -1;
    Gfx.Dest.x +=  Speedx;
    Gfx.Dest.y += Speedy;
}

void Ball::Bounce(int direction)
{
    switch(direction)
    {
        case 1: // ball has hit TOP/Bottom
        Speedy *= -1;
        Gfx.Dest.y += Speedy;
        break;
    }
}
void Ball::ResetBall(Window &App)
{
    Gfx.Dest.x = App.Width / 2;
    Gfx.Dest.y = App.Height / 2;
}

void Ball::Start()
{
    //Speed = 0;
    srand( (unsigned)time(NULL) );
    Direction = (int)rand() % 1;

    while(Speedx == 0 )
    {
        Speedx = (int)rand() % 4;

    }
    while(Speedy == 0)
    {
        Speedy = (int)rand() % 4;
    }

}

void Ball::Move()
{
    /*
    Gfx.Dest.x += Direction;
    Gfx.Dest.y += BallHeight;
    */
    Gfx.Dest.x += Speedx;
    Gfx.Dest.y += Speedy;
}
Ball::~Ball()
{
    //dtor
}
