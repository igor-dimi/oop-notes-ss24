#include <iostream>
#include <string>
#include <account.hh>



double Account::get_balance() const {return balance;}
void Account::withdraw(double amount){balance -= amount;}
Account::Account(double amount) {balance = amount;}
Account::Account() {balance = 100;}
Account::~Account(){;}




