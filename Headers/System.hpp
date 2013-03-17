#ifndef SYSTEM_H
#define SYSTEM_H

#define KEYS int

#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <SDL/SDL.h>

using namespace std;

class System
{
public:
    System();

    void Init();
    void SetRect(int x, int y, int h, int w);
    static int BindKey();

    virtual ~System();

protected:

private:
};


class Vector
{
public:
    int x,y;
};

#endif // SYSTEM_H
