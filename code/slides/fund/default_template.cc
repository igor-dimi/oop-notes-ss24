#include <iostream>


template <typename T, int n, int m = n> struct Matrix 
{
    static constexpr int dim1 = n;
    static constexpr int dim2 = m;
    T vals[n * m];
};


int main(int argc, char const *argv[])
{
    std::cout << Matrix<int, 2>::dim1 << " " << Matrix<int, 2>::dim2 << std::endl;
    std::cout << Matrix<int, 2, 3>::dim1 << " " << Matrix<int, 2, 3>::dim2 << std::endl;
    return 0;
}
