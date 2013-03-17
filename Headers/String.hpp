#ifndef STRING_H
#define STRING_H

#include <string>
#include <sstream>

// String.hpp is no longer depends on Font.hpp

using namespace std;


//template <class T>

class String
{
public:
    String();

    string    Text, Filename;

    int       RGB[3];
    SDL_Color TextColor;
    int       Size;

    void ChangeText(string text);
    void ChangeText(int var);
    void ChangeColor(int R, int G, int B);

    virtual ~String();
protected:
private:
};

#endif // STRING_H
