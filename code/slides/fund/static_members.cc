#include <iostream>

struct MyClass {
     static int counter;
};

int MyClass::counter = 0;

int main(int argc, char const *argv[])
{

    std::cout << "a) counter: " << MyClass::counter << std::endl;
    MyClass::counter++;
    std::cout << "b) counter: " << MyClass::counter << std::endl;
    MyClass a, b;
    a.counter++;
    std::cout << "c) counter: " << MyClass::counter << std::endl;
    b.counter++;
    std::cout << "d) counter: " << MyClass::counter << std::endl;

    return 0;
}


