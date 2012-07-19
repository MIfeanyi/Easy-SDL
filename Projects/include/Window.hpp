#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <SDL.h>

#include"Graphics.hpp"

using namespace std;




class Window
{
public:
    Window();
    Window(int WindowWidth, int WindowHeight, string WindowTitle, bool Full);

    void CreateWindow(int WindowWidth, int WindowHeight, string WindowTitle, bool Full);

    virtual ~Window();

    void Draw(Graphics &Gfx);
    void Update();
    void Clear();
    void Flip();

    int Width, Height;

protected:

    bool Fullscreen, IsOpen;
    string Title;
    SDL_Surface *Screen;
    SDL_Surface *Buffer;

private:
};

#endif // WINDOW_H
