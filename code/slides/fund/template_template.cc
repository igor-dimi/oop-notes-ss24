#include <iostream>

template<typename T, int n> struct Vector
{
    enum {dim = n};
    T vals[n];
};

template <typename T> T square(T x) {return x * x;}

template <template <typename T, int n> class V, typename T, int n>
T squaredNorm(const V<T, n> &vec)
{
    T sum = 0;
    for (int i = 0; i < n; i++) sum += square(vec.vals[i]);
    return sum;
}

int main(int argc, char const *argv[])
{
    Vector<double, 3> vec{1.0, 2.0, 3.0};
    std::cout << squaredNorm(vec) << std::endl;

    return 0;
}
