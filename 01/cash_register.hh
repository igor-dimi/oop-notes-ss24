#ifndef CASHR_H
#define CASHR_H

class CashRegister
{
    public:
        CashRegister();
        double get_total() const;
        int get_count() const;
        void clear();
        void add_item(double amount);
        void display() const;
    private:
        int item_count;
        double price_total;
};

#endif // !CASHR_h




