#include "order.hh"
#include <iostream>

Item::Item(std::string _description, double _price) : 
    description(_description),
    price(_price) {}

void Item::display() const
{
    std::cout << "Item: " << description << std::endl
              << "Price: " << price << std::endl;
}


Order::Order(std::string item_desc, double item_price, std::string _customer_name) :
    article(item_desc, item_price), 
    customer_name(_customer_name) {}

Order::Order(Item _article, std::string _customer_name)
: customer_name(_customer_name), article(_article) {}

void Order::display() const
{
    std::cout << "Customer: " << customer_name << std::endl;
    article.display();
}
