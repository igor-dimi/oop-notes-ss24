#include "account.hh"
#include <iostream>

int main(int argc, char const *argv[])
{
    Account a1;
    std::cout << a1.get_balance() << std::endl;
    a1.withdraw(100);
    std::cout << a1.get_balance() << std::endl;

    Account a2(500);
    std::cout << a2.get_balance() << std::endl;
    a2.withdraw(100);
    std::cout << a2.get_balance() << std::endl;

    Account *ap1 = new Account(300);
    Account *ap2 = ap1;

    std::cout << ap1->get_balance() << std::endl;
    std::cout << ap2->get_balance() << std::endl;

    ap1->withdraw(200);

    std::cout << ap1->get_balance() << std::endl;
    std::cout << ap2->get_balance() << std::endl;

    return 0;
}