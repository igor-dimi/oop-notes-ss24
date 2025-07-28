#include "employee.hh"

Employee::Employee(){}

std::string Employee::get_name() const
{
    return name;
}

void Employee::set_name(std::string _name)
{
    name = _name;
}

SalariedEmployee::SalariedEmployee(
    std::string name, double salary
)
{
    this->set_name(name);
    this->annual_salary = salary;
}

Manager::Manager(std::string name, double salary, double bonus)
    : SalariedEmployee(name, salary)
{
    weekly_bonus = bonus;
}

HourlyEmployee::HourlyEmployee(std::string name, double wage)
{
    set_name(name);
    hourly_wage = wage;
}

double HourlyEmployee::weekly_pay(int hours_worked) const
{
    double pay = hours_worked * hourly_wage;
    if(hours_worked > 40) {
        pay += ((hours_worked - 40) * 0.5) * hourly_wage;
    }
    return pay;
}

double SalariedEmployee::weekly_pay(int hours) const
{
    return annual_salary / 52;
}

double Manager::weekly_pay(int hours) const
{
    return SalariedEmployee::weekly_pay(hours) + weekly_bonus;
}