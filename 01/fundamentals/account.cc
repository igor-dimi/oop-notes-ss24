#include <iostream>
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

class Item
{
    public:
        Item(std::string description, double price);
        void display() const;
    private:
        std::string description;
        double price;
};

Item::Item(std::string _description, double _price) : 
    description(_description),
    price(_price) {}

void Item::display() const
{
    std::cout << "Item: " << description << std::endl
              << "Price: " << price << std::endl;
}

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


double Account::get_balance() const {return balance;}
void Account::withdraw(double amount){balance -= amount;}
Account::Account(double amount) {balance = amount;}
Account::Account() {balance = 100;}
Account::~Account(){;}

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

    Order o1("water", 18.5, "alice");
    o1.display();

    double* pp = new double(10);
    double price{10};
    std::cout << *pp << std::endl
              << price << std::endl;

    Order o2 {"bread", 1.175, "Bob"};
    o2.display();

    Item it1("butter", 1.5);
    it1.display();

    Order o3(it1, "Michael");
    Order o4(it1, "Janet");

    o3.display();
    o4.display();




    return 0;
}


