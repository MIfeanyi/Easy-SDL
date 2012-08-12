#ifndef STRING_H
#define STRING_H

#include<string>
#include <sstream>

#include"Font.hpp"

using namespace std;


//template <class T>

class String
{
public:
    String();

    //Font      font;
    string    Text, Filename;
    int       RGB[3];
    SDL_Color TextColor;

    void ChangeText(string text);
    void ChangeText(int var);
    void ChangeColor(int R, int G, int B);

    virtual ~String();
protected:
private:
};

#endif // STRING_H
