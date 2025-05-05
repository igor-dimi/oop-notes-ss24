#include <iostream>


template <typename T> T square(T x) {return x * x;}

int main(int argc, char const *argv[])
{
    std::cout << square<int>(5.34) << std::endl;
    std::cout << square<float>(3.14f) << std::endl;
    std::cout << square<double>(5.15) << std::endl;
    return 0;
}
