#include "time.h"
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

int operator-(Time a, Time b)
{
    return a.get_hours() * 60 + a.get_minutes()
        - b.get_hours() * 60 - b.get_minutes();
}

Time operator+(Time t, int minutes)
{
    int result_minutes = t.get_hours() * 60 + t.get_minutes() + minutes;
    return Time((result_minutes / 60) % 24, result_minutes % 60);
}

bool operator==(Time t1, Time t2)
{
    return t1 - t2 == 0;
}

bool operator!=(Time t1, Time t2)
{
    return t1 - t2 != 0;
}

bool operator<(Time t1, Time t2)
{
    return t1 - t2 < 0;
}

std::ostream& operator<<(std::ostream& out, Time const& t)
{
    out << t.get_hours() << ":"
        << std::setw(2) << std::setfill('0')
        << t.get_minutes();
        return out;
}

std::istream& operator>>(std::istream& in, Time& t)
{
    int hours;
    char separator;
    int minutes;
    in >> hours;
    in.get(separator); // read ':' character
    in >> minutes;
    t = Time(hours, minutes);
    return in;
}


Time Time::operator++()
{
    minutes++;
    return *this;
}

Time Time::operator++(int dummy)
{
    Time ret = *this;
    minutes++;
    return ret;
}