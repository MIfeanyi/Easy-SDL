#ifndef BALL_H
#define BALL_H

#include"System.hpp"
#include"Graphics.hpp"
#include"Window.hpp"


class Ball
{
public:
    Ball();

    void ResetBall(Window &App); // resets ball to the middle of the screen
    void Start(); // shoots off the ball
    void Bounce(); // changes the speed and bounces the ball
    void Bounce(int direction);
    void Move();
    void Random();
    Graphics Gfx;

    int Direction, BallHeight;
    int Speedx, Speedy;

    virtual ~Ball();
protected:
private:
};

#endif // BALL_H
