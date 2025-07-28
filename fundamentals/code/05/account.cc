#include <iostream>
#include <string>
#include "account.hh"


BankAccount::BankAccount() : balance(0) {}
void BankAccount::deposit(double amount) {balance += amount;}
void BankAccount::withdraw(double amount) {balance -= amount;}
double BankAccount::get_balance() const {return balance;}
// void BankAccount::month_end() {}
// std::string BankAccount::get_type() const {return "";}
void BankAccount::display() const
{
    std::cout << get_type() << ": " << get_balance();
}



SavingsAccount::SavingsAccount() {}
SavingsAccount::SavingsAccount(double _interest_rate) 
{
    interest_rate = _interest_rate;
}
void SavingsAccount::withdraw(double amount)
{
    double balance = get_balance();
    BankAccount::withdraw(amount);
    if (balance < min_balance) min_balance = balance;
}

void SavingsAccount::month_end()
{
    double interest = min_balance * interest_rate / 100;
    deposit(interest);
    min_balance = get_balance();
}

std::string SavingsAccount::get_type() const {return "savings";}

void CheckingAccount::withdraw(double amount)
{
    BankAccount::withdraw(amount);
    withdrawal_count++;
    if (withdrawal_count > FREE_WITHDRAWALS)
        BankAccount::withdraw(WITHDRAWAL_FEE);
}

void CheckingAccount::month_end()
{
    withdrawal_count = 0;
}

std::string CheckingAccount::get_type() const {return "checking";}








