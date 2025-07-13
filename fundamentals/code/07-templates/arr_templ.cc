#include <iostream>

template<typename T, int N>
struct Array : public Array<T, N - 1> 
{
    template <int M>
    T& entry () {return Array<T, M + 1>::val;}

    T val;
};

template<typename T>
struct Array<T, 0> {}; // empty base case


// there ain't nothing that I could do for you


int main(int argc, char const *argv[])
{
    Array<double, 2> a;
    a.entry<0>() = 2.0;

    std::cout << a.entry<0>() << std::endl;
    return 0;
}

