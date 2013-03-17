#ifndef FONT_H
#define FONT_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include<string>

using namespace std;

class Font
{
public:
    Font();
    void Load(string filename, int size);
    void ChangeSize(int size);
    TTF_Font*   font;
    string      Filename;

    virtual ~Font();
protected:
private:
};

#endif // FONT_H
