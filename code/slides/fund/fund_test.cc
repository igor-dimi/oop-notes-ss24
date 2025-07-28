#include <iostream>
#include "fund_defs.hh"
#include <limits>


template <typename T>
T Counter<T>::count = 0;

int extern x;

int main(int argc, char const *argv[])
{
    std::cout << "template-template parameters: " << std::endl;
    Vector<double, 3>  vec{1.0, 2.0, 3.0};
    std::cout << squaredNorm(vec) << std::endl;

    std::cout << "default template parameters: " << std::endl;
    Matrix<int, 2> squaredMatrix{{1, 2, 3, 4}};
    std::cout << squaredMatrix.dim1 << " " << squaredMatrix.dim2 << std::endl;
    std::cout << Matrix<int, 2>::dim1 << " " << Matrix<int, 2, 3>::dim2 << std::endl;

    std::cout << "renaming types: " << std::endl;
    VecPair3D2D vecPair{{1, 2, 3}, {4, 5}};
    std::cout << vecPair.s.dim << std::endl;
    std::cout << vecPair.t.dim << std::endl;

    std::cout << "access specifiers: " << std::endl;
    Customer customer{};
    customer.Deposit(100);
    std::cout << "balance: " << customer.GetBalance() << std::endl;


    std::cout << "constructors: " << std::endl;
    Vector3D vec1;
    Vector3D vec2(1, 2, 3);

    std::cout << vec1.vec[0] << " " << vec1.vec[1] << " "
              << " " << vec1.vec[2] << std::endl;

    
    std::cout << vec2.vec[0] << " " << vec2.vec[1] << " "
              << " " << vec2.vec[2] << std::endl;

    Vector3D vec3(vec2);

    std::cout << vec3.vec[0] << " " << vec3.vec[1] << " "
              << " " << vec3.vec[2] << std::endl;


    Vector3D vec4(std::move(vec2));
    std::cout << vec4.vec[0] << " " << vec4.vec[1] << " "
              << " " << vec4.vec[2] << std::endl;
    std::cout << vec2.vec[0] << " " << vec2.vec[1] << " "
              << " " << vec2.vec[2] << std::endl;

    std::cout << "test Counter: " << std::endl;

    Counter<int> c;

    std::cout << c.get() << std::endl;

    c.increment();
    std::cout << c.get() << std::endl;



    std::cout << "Max int: " << std::numeric_limits<int>::max() << "\n";
    std::cout << "Min int: " << std::numeric_limits<int>::min() << "\n";
    std::cout << "Max double: " << std::numeric_limits<double>::max() << "\n";
    std::cout << "Epsilon (double): " << std::numeric_limits<double>::epsilon() << "\n";
    std::cout << "Has infinity: " << std::numeric_limits<double>::has_infinity << "\n";


    return 0;
}
