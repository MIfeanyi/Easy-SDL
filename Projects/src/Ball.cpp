#include "Ball.hpp"

Ball::Ball()
{
    //ctor
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
    srand( (unsigned)time(NULL) );
    Direction = (int)rand() % 1;
    Speed = (int)rand() % 10;
    //decide if we want to go left / right

}

void Ball::Move()
{

}
Ball::~Ball()
{
    //dtor
}
