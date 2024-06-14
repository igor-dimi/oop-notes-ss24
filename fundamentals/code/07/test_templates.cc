#include <iostream>
#include <string>
#include "basics.hh"
#include <typeinfo>

typedef char* CHARS;
typedef CHARS const CPTR;

int& g(int& a, int& b) {return a;}
int g2(int& a, int& b) {return a;}

int f(int i = 3) {return i;}
int main(int argc, char const *argv[])
{

    int i = 30;
    int* const ip2 = &i;
    *ip2 = 40;
    int j = 50;
    const int* ip1 = &j;
    ip1 = ip2;
    
    const int i3 = 20;
    const int* const ip3 = &i3;

    // int a, b;
    // std::cin >> a >> b;
    // std::cout << max(a, b) << std::endl;
    const std::string s1 = "mathematics";
    const std::string s2 = "math";
    std::cout << max(3, 10) << std::endl;
    bool val = (s1 < s2);
    std::cout << val << std::endl;
    const std::string s3 = (s1 < s2 ? s2 : s1);
    std::cout << s3 << std::endl;
    const std::string s4 = ::max<const std::string>(s1, s2);


    int i4 = 30;
    int const& ir = i4;

    // there really a
    

    std::cout << i4 << std::endl;

    std::cout << f() << std::endl;
    std::cout << ::max2(10.0, 4) << std::endl;
    std::cout << ::max('a', 'b') << std::endl;
    std::cout << ::max('a', 3) << std::endl;
    // std::cout << ::max2<double, int, double>(10, 4) << std::endl;
    std::cout << ::max2<double>(10, 3) << std::endl;
    ::max2(4, 7.2);
    ::max2<long double>(7.2, 4);
    ::max2<double>(7.2, 4);
    auto a = ::max2<int>(8, 20);
    std::cout << "a: " << a <<", " <<typeid(a).name() << std::endl;

    int c = 7;
    int d = 42;
    auto m1 = ::max(a, b);

    std::string s3 = "hey";
    std::string s4 = "you";
    auto m2 = ::max(s3, s4);

    int* p1 = &c;
    int* p2 = &d;
    auto m3 = ::max(p1, p2);

    char const* x = "hello";
    char const* y = "world";
    auto m4 = ::max(x, y);

    return 0;
}
