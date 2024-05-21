#ifndef TIM_H
#define TIM_H

#include <iostream>

class Time
{
    public: 
        Time();
        Time(int h, int m);
        int get_hours() const;
        int get_minutes() const;
        Time operator+(int min) const;
        Time operator++();
        Time operator++(int dummy);
    private:
        int hours;
        int minutes;
};

int operator-(Time a, Time b);
// Time operator+(Time a, int minutes);
bool operator==(Time a, Time b);
bool operator!=(Time a, Time b);
bool operator<(Time a, Time b);
std::ostream& operator<<(std::ostream& out, Time a);
std::istream& operator>>(std::istream& in, Time& a);


#endif // !TIM_H
