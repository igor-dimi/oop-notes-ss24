#include "order.hh"
#include <iostream>

int main(int argc, char const *argv[])
{
    
    Order o1("water", 18.5, "alice");
    o1.display();

    double* pp = new double(10);
    double price{10};
    std::cout << *pp << std::endl
              << price << std::endl;

    Order o2 {"bread", 1.175, "Bob"};
    o2.display();

    Item it1("butter", 1.5);
    it1.display();

    Order o3(it1, "Michael");
    Order o4(it1, "Janet");

    o3.display();
    o4.display();

    return 0;
}
