#include "car.hh"
#include <iostream>

int main(int argc, char const *argv[])
{
    Car c1("Audi", "sport", "Volkswagen", 220);
    c1.display();
    std::cout << std::endl;

    Engine e("Toyota", 135);
    Car c2("Honda", "family", e);
    c2.display();
    std::cout << std::endl;

    return 0;
}
