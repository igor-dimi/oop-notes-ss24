#include "string2.hh"
#include <iostream>

int main(int argc, const char** argv) {

    String s1("Fred");
    String s2("Ann");
    s1.display(); std::cout << std::endl;
    s2.display(); std::cout << std::endl;
    
    s1 = s2;
    
    s1.display(); std::cout << std::endl;
    s2.display(); std::cout << std::endl;

    s2 = s2;

    s2.display(); std::cout << std::endl;

    s2 = String("George");

    s2.display(); std::cout << std::endl;

    s2 = "Bob"; // implicit type conversion string -> String

    s2.display(); std::cout << std::endl;

    String s3 = s2;

    s3.display(); std::cout << std::endl;

    repeat(s3, 4);
    std::cout << std::endl;

    String s4;
    s4.display(); std::cout << std::endl;

    s2.substr(1, 20).display(); std::cout << std::endl;
    s2 = "Michael";
    s2.substr(1, 20).display(); std::cout << std::endl;
    
    return 0;
}