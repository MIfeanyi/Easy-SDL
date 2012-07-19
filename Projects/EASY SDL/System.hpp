#ifndef SYSTEM_H
#define SYSTEM_H


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
