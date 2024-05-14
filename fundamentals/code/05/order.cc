#include "order.hh"
#include <iostream>

Item::Item(std::string _id, 
    std::string _desc,
    double _price) :
    id(_id),
    description(_desc),
    price(_price) {}

std::string Item::get_id() {return id;}
std::string Item::get_description() {return description;}
double Item::get_price() {return price;}

void Item::display()
{
    std::cout << "id: " << id << std::endl
              << "description: " << description << std::endl
              << "price: " << price << std::endl;
}

Order::Order(std::string order_id, 
        std::string _customer_name, 
        std::string item_id,
        std::string item_desc, 
        double item_price) :
    
    id(order_id),
    customer_name(_customer_name)
{
    items.push_back({item_id, item_desc, item_price});
}

Order::Order(std::string _id, 
    std::string _customer_name, 
    Item item) :

    id(_id),
    customer_name(_customer_name)
{
    items.push_back(item);
}

std::string Order::get_order_id() {return id;}
std::string Order::get_customer_name() {return customer_name;}
double Order::get_total_price() const
{
    double sum = 0;
    for (auto it : items) {
        sum += it.get_price();
    }
    return sum;
}

int Order::get_item_count() const
{
    return items.size();
}

void Order::add_item(Item item)
{
    items.push_back(item);
}

void Order::display() const
{
    std::cout << "order id: " << id << std::endl
              << "customer name: " << customer_name << std::endl
              << "  Items: " << std::endl << std::endl;
    
    for (auto it : items) {
        it.display();
        std::cout << std::endl;
    }
    std::cout << "item count: " << get_item_count() << std::endl;
    std::cout << "total price: " << get_total_price() << std::endl;
    

}






