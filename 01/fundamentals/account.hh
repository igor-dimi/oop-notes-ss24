#include <string>


class Account
{
    public : 
        Account(double amount);
        Account();
        ~Account();
        double get_balance() const;
        void withdraw(double amount);
    private :
        double balance;
};