#include "cash_register.hh"
#include <iostream>


void display_n(CashRegister cr)
{
    cr.display();
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    CashRegister cr1;
    display_n(cr1);
    cr1.add_item(15.4); 
    display_n(cr1);
    cr1.clear();
    display_n(cr1);
    return 0;
}
