#include "String.hpp"

String::String()
{
    //ctor
}

void String::ChangeColor(int R, int G, int B)
{
    TextColor = { R, G, B};
}
void String::ChangeText(string text)
{
    stringstream out;
    out<<text;
    Text = out.str();
}

void String::ChangeText(int var)
{
    stringstream out;
    out<<var;
    Text = out.str();
}

/*



*/

String::~String()
{
    //dtor
}
