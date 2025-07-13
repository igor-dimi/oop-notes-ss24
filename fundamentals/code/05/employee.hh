#ifndef EMP_H
#define EMP_H

#include <string>

class Employee
{
    public: 
        Employee();
        std::string get_name() const;
        void set_name(std::string name);
        virtual double weekly_pay(int hours) const = 0;
        // ...
    private:
        std::string name;
};

class HourlyEmployee : public Employee
{
    public:
        HourlyEmployee(std::string name, double wage);
        virtual double weekly_pay(int hours) const override;
    private:
        double hourly_wage;
};

class SalariedEmployee : public Employee
{
    public:
        SalariedEmployee(std::string name, double salary);
        virtual double weekly_pay(int hours) const override;
    private:
        double annual_salary;
};

class Manager : public SalariedEmployee
{
    public:
        Manager(std::string name, double salary, double bonus);
        virtual double weekly_pay(int hours) const override;
    private:
        double weekly_bonus;
};



#endif // !EMP_H
