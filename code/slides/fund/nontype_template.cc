#include <iostream>

template<typename T, int n> struct Vector
{
    // enum {dim = n};
    int dim = n;
    T vals[n];
};

int main(int argc, char const *argv[])
{
    int arr[5] = {1, 2, 3, 4, 5};
    Vector<int, 5> vec{};
    std::cout << vec.dim << std::endl;
    return 0;
}
