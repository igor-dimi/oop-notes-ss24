#include "time.hh"
#include <iostream>


void g(int& a)
{
    a++;
}

int main(int argc, const char** argv) {
    Time t1(6, 0);
    Time t2(t1 + 45);
    std::cout << t2.get_hours() << " " << t2.get_minutes() 
        << std::endl;

    std::cout << t1 << " " <<  t2 << std::endl;

    // Time t;
    // std::cout << t << std::endl;
    // std::cin >> t;
    // std::cout << t << std::endl;


    // int z = 4;
    // std::cout << z++ << std::endl;
    // z = 4;
    // std::cout << ++z << std::endl;

    std::cout << ++t1 << std::endl;
    t1 = Time(6 ,0);
    std::cout << t1++ << std::endl;
    int a = 3;
    int& b = a;
    g(b);
    std::cout << a << std::endl;
    std::pair<int, int> p{1, 2};

    std::cout << p.first << " " << p.second << std::endl;


    return 0;

}