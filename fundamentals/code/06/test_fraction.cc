#include "fraction.hh"
#include <iostream>

int main(int argc, const char** argv) {
    Fraction f(1, 2);
    Fraction g(1, 3);
    std::cout << std::boolalpha;
    std::cout << "f: " << f << " " << "g: " << g << std::endl;
    std::cout << "f + g: " << f + g << std::endl;
    std::cout << "f - g: " << f - g << std::endl;
    std::cout << "f * g: " << f * g << std::endl;
    std::cout << "f / g: " << f / g << std::endl;
    bool val = f == g;
    bool val2 = f != g;
    std::cout << "f == g: " << val << std::endl;
    std::cout << "f != g: " << val2 << std::endl;

    std::cout << "1 + f: " << 1 + f << std::endl;
    std::cout << "1 - f: " << 1 - f << std::endl;
    std::cout << "1 / f: " << 1 / f << std::endl;
    bool val3 = 1 == f;
    bool val4 = 1 != f;
    std::cout << "1 == f: " << val3 << std::endl;
    std::cout << "1 != f: " << val4 << std::endl;


    std::cout << "f + 1: " << f + 1 << std::endl;
    std::cout << "f - 1: " << f - 1 << std::endl;
    std::cout << "f / 1: " << f / 1 << std::endl;
    bool val5 = f == 1;
    bool val6 = f != 1;
    std::cout << "f == 1: " << val5 << std::endl;
    std::cout << "f != 1: " << val6 << std::endl;

    return 0;
}
