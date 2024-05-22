#include "fraction.hh"
#include <stdlib.h>

int Fraction::gcd(int a, int b)
{
    if (a == 0) return b;
    if (b == 0) return a;
    return gcd(b, a%b);
}

Fraction::Fraction(int n, int d)
{
    int g = gcd(abs(n), abs(d));
    if (d > 0) {
        numerator = n/g;
        denominator = d/g;
    }
    if (d < 0) {
        numerator = -n / g;
        denominator = -d / g;
    }
}

Fraction::Fraction(int n)
{
    numerator = n;
    denominator = 1;
}

Fraction Fraction::operator+(const Fraction& other) const
{
    return Fraction(numerator * other.denominator
        + other.numerator * denominator,
        denominator * other.denominator);
}

Fraction Fraction::operator*(const Fraction& other) const
{
    return Fraction(numerator * other.numerator,
        denominator * other.denominator);
}

Fraction operator+(int n, const Fraction& f)
{
    return f + n;
}


Fraction operator*(int n, const Fraction& f)
{
    return f * n;
}

Fraction operator-(const Fraction& f)
{
    return f * -1;
}


Fraction Fraction::operator-(const Fraction& other) const
{
    return *this + (-other);
}

Fraction operator-(int n, const Fraction& f)
{
    return n + (-f);
}

Fraction Fraction::inverse() const
{
    return Fraction(denominator, numerator);
}


Fraction Fraction::operator/(const Fraction& other) const
{
    return *this * other.inverse();
};

Fraction operator/(int n, const Fraction& f)
{
    return n * f.inverse();
}

bool Fraction::operator<(const Fraction& other) const
{
    return numerator * other.denominator
        < denominator * other.numerator;
}


bool Fraction::operator>(const Fraction& other) const
{
    return other < *this;
}

bool operator<(int n, const Fraction& f)
{
    return f > n;
}

bool operator>(int n, const Fraction& f)
{
    return f < n;
}

bool Fraction::operator<=(const Fraction& other) const
{
    return !(*this > other);
}

bool Fraction::operator>=(const Fraction& other) const
{
    return !(*this < other);
}

bool operator>=(int n, const Fraction& g) {return g <= n;}
bool operator<=(int n, const Fraction& g) {return g >= n;}

bool Fraction::operator!=(const Fraction& other) const
{
    return (*this < other || *this > other);
} 

bool Fraction::operator==(const Fraction& other) const
{
    return (*this <= other && *this >= other);
}

bool operator!=(int n, const Fraction& f) {return f != n;}
bool operator==(int n, const Fraction& f) {return f == n;}

void Fraction::print(std::ostream& out) const
{
    out << numerator << "/" << denominator;
}

std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
    f.print(out);
    return out;
}

void Fraction::read(std::istream& in)
{
    char separator;
    in >> numerator >> separator >> denominator;
}

std::istream& operator>>(std::istream& in,  Fraction& f)
{
    f.read(in);
    return in;
}

