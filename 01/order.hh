#ifndef ORDR_H
#define ORDR_H
#include <string>

class Item
{
    public:
        Item(std::string description, double price);
        void display() const;
    private:
        std::string description;
        double price;
};


class Order
{
    public:
        Order(std::string item_desc, double item_price, std::string customer_name);
        Order(Item article, std::string customer_name);
        void display() const;
    private: 
        Item article;
        std::string customer_name;
};
#endif // !ORDR_H