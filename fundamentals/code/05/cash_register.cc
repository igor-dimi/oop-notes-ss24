#include "cash_register.hh"
#include <iostream>

CashRegister::CashRegister()
{
    item_count = 0;
    price_total = 0;
}
int CashRegister::get_count() const {return item_count;}
double CashRegister::get_total() const {return price_total;}
void CashRegister::display() const {
    std::cout << "count: " << get_count() << std::endl
              << "sum: " << get_total() << std::endl;
}
void CashRegister::clear() 
{
    item_count = 0; 
    price_total = 0;
}
void CashRegister::add_item(double amount)
{
    item_count++;
    price_total += amount;
}