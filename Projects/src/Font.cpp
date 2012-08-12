#include "Font.hpp"

Font::Font()
{
    //ctor
}

void Font::Load(string filename, int size)
{
    Filename = filename;
    font = TTF_OpenFont( filename.c_str(), size);
}

void Font::ChangeSize(int size)
{
    font = TTF_OpenFont( Filename.c_str(), size);
}

Font::~Font()
{
    //dtor
}
