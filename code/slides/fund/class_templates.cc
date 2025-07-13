#include <iostream>

template <typename T> struct Pair
{
    T a;
    T b;
};

int main(int argc, char const *argv[])
{

    Pair<int> ip{1, 2};
    std::cout << "a: " << ip.a << " " << "b: " << ip.b << std::endl;
    Pair<float> fp{1.4, 2.5};
    std::cout << "a: " << fp.a << " " << "b: " << fp.b << std::endl;
    Pair<Pair<int>> ipp{ip, ip};
    std::cout << "a: " << ipp.a.a << " " << "b: " << ipp.b.b << std::endl;
    return 0; 
}
