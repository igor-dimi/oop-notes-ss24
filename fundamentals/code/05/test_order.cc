#include "order.hh"
#include <iostream>

int main(int argc, char const *argv[])
{
    
    Order o1(
        "1",
        "bob",
        "123",
        "water",
        0.95
    );
    o1.display();
    Item i1(
        "2",
        "bread",
        1.25
    );
    o1.add_item(i1);
    std::cout << std::endl;
    o1.display();


    Item i2(
        "3",
        "cola",
        2.5
    );

    Order o2(
        "3",
        "alice",
        i2
    );

    std::cout << std::endl;
    o2.display();

    std::cout << std::endl;
    i1.display();
}
