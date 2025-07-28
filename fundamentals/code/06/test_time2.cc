#include "time2.hh"
#include <iostream>

int main(int argc, const char** argv) {
    std::cout << std::boolalpha;
    Time t1(3, 40);
    Time t2(5, 20);
    t1.display();
    std::cout << std::endl;
    t2.display();
    std::cout << std::endl;
    std::cout << t2 - t1 << std::endl;
    t2 = t2 + 30;
    t2.display();
    std::cout << std::endl;
    Time t3(3, 40);
    std::cout << (t1 == t3) << ", " << (t2 == t3) << std::endl;
    std::cout << (t1 != t3) << std::endl;
    std::cout << "t1: " << t1 << std::endl
              << "t2: " << t2 << std::endl
              << "t3: " << t3 << std::endl;

    Time t4(10, 15);
    // std::cin >> t4;
    std::cout << "t4: " << t4 << std::endl;
    std::cout << ++t4 << std::endl;
    std::cout << t4++ << std::endl;
    std::cout << t4 << std::endl;

    return 0;
}


// how could you tell em that othe tie .. aer you