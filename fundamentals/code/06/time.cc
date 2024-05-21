#include "time.hh"
#include <iomanip>
#include <ios>

Time::Time() {hours = minutes = 0;}
Time::Time(int h, int m) {hours = h; minutes = m;}
int Time::get_hours() const {return hours;}
int Time::get_minutes() const {return minutes;}

int operator-(Time a, Time b)
{
    return a.get_hours() * 60 + a.get_minutes()
        - b.get_hours() * 60 - b.get_minutes();
}

// Time operator+(Time a, int minutes)
// {
//     int result_minutes = a.get_hours() * 60 + a.get_minutes()
//         + minutes;
//     return Time((result_minutes / 60) % 24, result_minutes % 60);
// }

bool operator==(Time a, Time b) {return a - b == 0;}
bool operator!=(Time a, Time b) {return a - b != 0;}
bool operator<(Time a, Time b) {return a - b < 0;}
std::ostream& operator<<(std::ostream& out, Time a)
{
    out << a.get_hours() << ":"
        << std::setw(2) << std::setfill('0')
        << a.get_minutes();
    return out;
}
std::istream& operator>>(std::istream& in, Time& a)
{
    int hours;
    char seperator;
    int minutes;
    in >> hours;
    in.get(seperator);
    in >> minutes;
    a = Time(hours, minutes);
    return in;
}


Time Time::operator+(int min) const
{
    int res_minutes = hours * 60 + minutes + min;
    return Time((res_minutes / 60) % 24, res_minutes % 60);
}

Time Time::operator++()
{
    minutes++;
    return *this;
}

Time Time::operator++(int dummy)
{
    Time t = *this;
    minutes++;
    return t;
}
