#ifndef PADDLE_H
#define PADDLE_H

#include"Window.hpp"
#include"Graphics.hpp"
#include"Ball.hpp"

class Paddle
{
public:
    Paddle();

    Graphics Gfx;

    int Speed;

    void Move(bool Direction); //Up or Down
    void Move(Ball &ball);
    void Reset(Window &App, bool Direction);

    virtual ~Paddle();
protected:
private:
};

#endif // PADDLE_H
