#include <iostream>

struct IndependentBase
{
    typedef int T;
};

template <typename T>
struct Derived : IndependentBase
{
    T val;
    Derived(T _val) : val(_val) {}
};

int main(int argc, char const *argv[])
{
    /* code */
    std::cout << Derived<double>(2.5).val << std::endl;
    return 0;
}
