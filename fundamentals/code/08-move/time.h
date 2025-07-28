#ifndef TIM_H
#define TIM_H
#include <iostream>

class Time {
    public :
        Time ();
        Time (int h, int m);
        int get_hours() const;
        int get_minutes() const;
        Time operator++();
        Time operator++(int dummy);
        // Time operator++(int dummy);
    private :
        int hours;
        int minutes;
};

int operator-(Time, Time);
Time operator+(Time t, int minutes);
bool operator==(Time, Time);
bool operator!=(Time, Time);
bool operator<(Time, Time);

std::ostream& operator<<(std::ostream&, Time const&);
std::istream& operator>>(std::istream&, Time&);



#endif // !TIM_H