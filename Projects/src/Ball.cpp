#include "Ball.hpp"

Ball::Ball()
{
    //ctor
    Speed = 0;
}

void Ball::Bounce()
{

}

void Ball::ResetBall(Window &App)
{
    Gfx.Dest.x = App.Width / 2;
    Gfx.Dest.y = App.Height / 2;
}

void Ball::Start()
{
    Speed = 0;
    srand( (unsigned)time(NULL) );
    Direction = (int)rand() % 1;

    while(Speed == 0)
    {
        Speed = (int)rand() % 3;
    }
    //decide if we want to go left / right

}

void Ball::Move()
{
    /*
    Gfx.Dest.x += Direction;
    Gfx.Dest.y += BallHeight;
    */
    Gfx.Dest.x +=  Speed;
    Gfx.Dest.y += Speed;
}
Ball::~Ball()
{
    //dtor
}
