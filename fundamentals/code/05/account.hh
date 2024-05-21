#ifndef ACC_H
#define ACC_H

#include <string>

class BankAccount
{
    public:
        BankAccount();
        virtual void deposit(double amount);
        virtual void withdraw(double amount);
        virtual void month_end() = 0;
        double get_balance() const;
        virtual std::string get_type() const = 0;
        void display() const;
    private:
        double balance;
};

class SavingsAccount : public BankAccount
{
    public:
        SavingsAccount();
        SavingsAccount(double interest_rate);
        void set_interest_rate(double rate);
        virtual void withdraw(double amount) override;
        virtual void month_end() override;
        virtual std::string get_type() const override;
    private:
        double interest_rate;
        double min_balance;
};

class CheckingAccount : public BankAccount
{
    public :
        const int FREE_WITHDRAWALS = 3;
        const double WITHDRAWAL_FEE = 1;
        virtual void withdraw(double amount) override;
        virtual void month_end() override;
        virtual std::string get_type() const override;
    private:
        int withdrawal_count;
};

#endif // !ACC_H
