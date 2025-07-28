#include <iostream>

template <int N>
struct Factorial
{
    // static int value = Factorial<N - 1>::value * N;
    enum { value = Factorial<N - 1>::value * N};
};


// template specializatoin for base case:
template<>
struct Factorial<0>
{
    // int value = 1; // why doesn't this work
    enum {value = 1};
};

constexpr int factorial(int n) {return (n > 0) ? (factorial(n - 1) * n) : 1;}


int main(int argc, char const *argv[])
{
    // test factorial
    std::cout << Factorial<0>::value << " " << factorial(0) << std::endl;
    std::cout << Factorial<1>::value << " " << factorial(1) << std::endl;
    std::cout << Factorial<2>::value << " " << factorial(2) << std::endl;
    std::cout << Factorial<3>::value << " " << factorial(3) << std::endl;
    std::cout << Factorial<4>::value << " " << factorial(4) << std::endl;
    std::cout << Factorial<5>::value << " " << factorial(5) << std::endl;
    std::cout << Factorial<6>::value << " " << factorial(6) << std::endl;
    std::cout << Factorial<7>::value << " " << factorial(7) << std::endl;
    return 0;
}
