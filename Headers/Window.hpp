#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <SDL/SDL.h>

#include "String.hpp"
#include "Graphics.hpp"

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
    void Clear(int R, int G, int B);
    void Flip();
    void LimitFramerate();
    void DrawText( String &DrawString, Font &font, int x, int y);
    void RenderText();

    int Width, Height;

    //for FPS limiter
    int FPS, Tick;

protected:

    bool Fullscreen, IsOpen;
    string Title;
    SDL_Surface *Screen;
    SDL_Surface *Text;
    SDL_Surface *Buffer;

private:
};

#endif // WINDOW_H
