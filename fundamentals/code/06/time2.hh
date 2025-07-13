#ifndef TIM2_H
#define TIM2_H
#include <iostream>

class Time 
{
    public :
        Time ();
        Time (int h, int m);
        int get_hours() const;
        int get_minutes() const;
        void display() const;
        // Time operator+(int min) const;
        Time operator++();
        Time operator++(int dummy);
    private :
        int hours;
        int minutes;

};


int operator-(const Time& a, const Time& b);
Time operator+(const Time& a, int minutes);
bool operator==(const Time& a, const Time& b);
bool operator!=(const Time& a, const Time& b);
bool operator<(const Time& a, const Time& b);
std::ostream& operator<<(std::ostream& out, const Time& a);
std::istream& operator>>(std::istream& in, Time& a);

#endif // !TIM2_H