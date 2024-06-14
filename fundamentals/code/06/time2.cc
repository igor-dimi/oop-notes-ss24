#include "time2.hh"
#include <iostream>
#include <iomanip>

Time::Time()
{
    hours = 0;
    minutes = 0;
}

Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}

int Time::get_hours() const 
{
    return hours;
}

int Time::get_minutes() const
{
    return minutes;
}

int operator-(const Time& a, const Time& b)
{
    return a.get_hours() * 60 + 
        a.get_minutes()
        - b.get_hours() * 60 - b.get_minutes();
}

Time operator+(const Time& a, int minutes)
{
    int result_minutes = a.get_hours() * 60 + a.get_minutes() + minutes;
    return Time((result_minutes / 60) % 24, result_minutes % 60);
}

bool operator==(const Time& a, const Time& b)
{
    return a - b == 0;
}

bool operator!=(const Time& a, const Time& b)
{
    return !(a == b);
}

bool operator<(const Time& a, const Time& b)
{
    return a - b < 0;
}

void Time::display() const
{
    std::cout << hours << ":" << minutes;
}

std::ostream& operator<<(std::ostream& out, const Time& a)
{
    out << a.get_hours() << ":" 
        << std::setw(2) << std::setfill('0')
        << a.get_minutes();
    return out;
}

std::istream& operator>>(std::istream& in, Time& a)
{
    int hours;
    char separator;
    int minutes;
    in >> hours;
    in.get(separator); // Read: character
    in >> minutes;
    a = Time(hours, minutes);
    return in;

}

// Time Time::operator+(int min) const
// {
//     int result_minutes = hours * 60 + minutes + min;
//     return Time((result_minutes / 60) % 24, result_minutes % 60);
// }

Time Time::operator++()
{
    *this = *this + 1;
    return *this;
}

//postfix increment
Time Time::operator++(int dummy)
{
    Time t = *this;
    *this = *this + 1;
    return t;
}



