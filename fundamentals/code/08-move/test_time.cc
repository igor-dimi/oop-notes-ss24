#include "time.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    Time t1;
    Time t2(3, 30);
    int minutes = t2 - t1;
    std::cout << minutes << std::endl;

    auto t = t1 + 300;
    auto m = t - t1;
    std::cout << m << std::endl;

    std::cout << t 
              << std::endl 
              << t1
              << std::endl;

    // {
    //     Time t;
    //     std::cin >> t;
    //     std::cout << t << std::endl;
    // }

    {
        Time t;
        std::cout << ++t << std::endl;
        
        Time t2;
        std::cout << "t2: " << t2++ << std::endl;
        std::cout << "t2: " << t2 << std::endl;
    }


    return 0;
}

