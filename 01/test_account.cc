#include "account.hh"
#include <iostream>
#define nl std::endl

int main(int argc, char const *argv[])
{
    Account a1;
    std::cout << "a1: " << a1.get_balance() << std::endl;
    std::cout << nl << "withdraw 100 from a1" << nl;
    a1.withdraw(100);
    std::cout <<  "a1: " << a1.get_balance() << std::endl;

    Account a2(500);
    std::cout << "a2: " << a2.get_balance() << std::endl;
    std::cout << nl << "withdraw 100 from a2" << nl;
    a2.withdraw(100);
    std::cout <<  "a2: " << a2.get_balance() << std::endl;

    Account *ap1 = new Account(300);
    Account *ap2 = ap1;

    std::cout << nl << "ap1 points to an account on heap, ap2 points to the same account" << nl;
    std::cout << "*ap1:" << ap1->get_balance() << std::endl;
    std::cout << "*ap2:" << ap2->get_balance() << std::endl;

    std::cout << nl <<  "withdraw 200 from *ap1" << nl;
    ap1->withdraw(200);

    std::cout << "*ap1:" << ap1->get_balance() << std::endl;
    std::cout << "*ap2:" << ap2->get_balance() << std::endl;

    Account a3(250);
    Account &a4 = a3;

    std::cout << "a3: " <<  a3.get_balance() << nl;
    std::cout << "a4: " << a4.get_balance() << nl;

    std::cout << nl << "withdraw 25 from a3" << nl;
    a3.withdraw(25);

    std::cout << "a3: " <<  a3.get_balance() << nl;
    std::cout << "a4: " << a4.get_balance() << nl;


    Account *ap3 = &a1;
    std::cout << "*ap3: " << ap3->get_balance() << nl;
    ap3->withdraw(-20);
    std::cout << "*ap3: " << ap3->get_balance() << nl;
    std::cout << "a1: " << a1.get_balance() << nl;



    Account a5(a1);
    Account a6 {a1};
    Account a7 = a1;
    std::cout << "a5: " << a5.get_balance() << nl;
    std::cout << "a6: " << a6.get_balance() << nl;
    std::cout << "a7: " << a7.get_balance() << nl;

    Account a {20};
    Account &b = a;

    std::cout << "a: " << a.get_balance() << nl;
    std::cout << "b: " << b.get_balance() << nl;

    b.withdraw(5);
    std::cout << "a: " << a.get_balance() << nl;
    std::cout << "b: " << b.get_balance() << nl;

    a.withdraw(5);
    std::cout << "a: " << a.get_balance() << nl;
    std::cout << "b: " << b.get_balance() << nl;


    return 0;
}