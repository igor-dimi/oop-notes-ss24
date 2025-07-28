#include <iostream>

struct A
{
    A() = default;
    A(int _x) {x = _x;}
    int x = 0;
};


struct B
{
    B() = default;
    B(int _y) {y = _y;}
    int y = 0;
};

struct C : A, B
{
    C() = default;
    C(int _x, int _y, int _z) : A(_x), B(_y), z(_z) {}
    int z  = 0;
};

int main(int argc, char const *argv[])
{
    A a1;
    A a2(30);

    std::cout << "a1: " << a1.x << " " << "a2: " << a2.x << std::endl;


    C c1;
    std::cout << "c1: " << c1.x << " " << c1.y << " " << c1.z << std::endl;

    C c2(1, 2, 3);
    std::cout << "c2: " << c2.x << " " << c2.y << " " << c2.z << std::endl;


    return 0;
}
