#include <iostream>

int square(int i) {return i * i;}
int applyTwice(int f(int), int i) {return f(f(i));}

int main(int argc, char const *argv[])
{
    int (*f)(int) = square; // or int (*f)(int) = &square; but & can be omitted
    std::cout << applyTwice(f, 7) << std::endl; // or std::cout << applyTwice(*f, 7) << std::endl; but * can be ommitted
    return 0;
}
