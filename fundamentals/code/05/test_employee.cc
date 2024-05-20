#include "employee.hh"
#include <iostream>
#include <vector>

int main(int argc, const char** argv) {
    std::vector<Employee*> employees;
    employees.push_back(new HourlyEmployee("Harry", 30));
    employees.push_back(new SalariedEmployee("Marry", 52000));
    employees.push_back(new Manager("Michael", 104000, 50));

    for (auto e : employees)
    {
        std::cout << "hours worked by " << e->get_name() << ": ";
        int hours;
        std::cin >> hours;
        std::cout << "Salary: " << e->weekly_pay(hours) << std::endl;
    }

    return 0;
}