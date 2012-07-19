#ifndef SYSTEM_H
#define SYSTEM_H

#define ERROR 5

#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class System
{
public:
    System();

    void Init();
    void SetRect(int x, int y, int h, int w);

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
