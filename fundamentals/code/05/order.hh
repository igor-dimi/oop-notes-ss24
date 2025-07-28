#ifndef ORDR_H
#define ORDR_H
#include <string>
#include <vector>

class Item
{
    public:
        Item(std::string id, 
            std::string description, 
            double price);

        std::string get_id();
        std::string get_description();
        double get_price();

        void display();

    private:
        std::string id;
        std::string description;
        double price;
};


class Order
{
    public:
        Order(std::string order_id, 
            std::string customer_name, 
            std::string item_id,
            std::string item_desc, 
            double item_price);

        Order(std::string id, 
            std::string customer_name, 
            Item item);

        std::string get_order_id();
        std::string get_customer_name();
        double get_total_price() const;
        int get_item_count() const;
        void add_item(Item item);

        void display() const;
    private: 
        std::string id;
        std::string customer_name;
        std::vector<Item> items;
};
#endif // !ORDR_H
