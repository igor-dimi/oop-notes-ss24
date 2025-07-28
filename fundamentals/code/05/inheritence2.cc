#include <iostream>

class A
{
    public :
        virtual int get_a() = 0;
    private:
        int a;
};

class B
{
    public :
        B(A& _a) : aObj(_a) {}
    private :
        A& aObj;
};