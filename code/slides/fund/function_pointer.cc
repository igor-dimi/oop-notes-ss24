#include <iostream>

int square(int i) {return i * i;}
int applyTwice(int (*f)(int), int i) {return f(f(i));}
// or int applyTwice(int f(int), int i) {return f(f(i));} the * in the signature can be omitted

int main(int argc, char const *argv[])
{
    int (*f)(int) = square; // or int (*f)(int) = &square; but & can be omitted
    std::cout << "a): " <<  applyTwice(f, 7) << std::endl; // or std::cout << applyTwice(*f, 7) << std::endl; but * can be ommitted
    std::cout << "b): " <<  applyTwice(&square, 7) << std::endl; // or std::cout << applyTwice(*f, 7) << std::endl; but * can be ommitted
    std::cout << "c): " << applyTwice(square, 7) << std::endl; // or std::cout << applyTwice(*f, 7) << std::endl; but * can be ommitted
    return 0;
}
