#include "Paddle.hpp"

Paddle::Paddle()
{
    //ctor
}

void Paddle::Move(bool Direction)
{
    if(Direction)
    {
        Gfx.Dest.y -= Speed;
    }
    else
    {
        Gfx.Dest.y += Speed;
    }
}

void Paddle::Move(Ball &ball) // for AI
{
    if(Gfx.Dest.y >  ball.Gfx.Dest.y)
    {
        Gfx.Dest.y -= Speed;
    }
    if(Gfx.Dest.y <  ball.Gfx.Dest.y)
    {
        Gfx.Dest.y += Speed;
    }
}

void Paddle::Reset(Window &App, bool Direction)
{
    Gfx.Dest.y = App.Height / 2;

    if(Direction)
    {
        Gfx.Dest.x = App.Width - 32;
    }
    else
    {
        Gfx.Dest.x = 32;
    }
}

Paddle::~Paddle()
{
    //dtor
}
