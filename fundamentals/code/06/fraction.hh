#ifndef FRA_H
#define FRA_H

#include <iostream>

class Fraction
{
    public: 
        Fraction(int n, int d);
        Fraction(int n);
        Fraction operator+(const Fraction& other) const;
        Fraction operator-(const Fraction& other) const;
        Fraction operator*(const Fraction& other) const;
        Fraction operator/(const Fraction& other) const;
        bool operator<(const Fraction& other) const;
        bool operator>(const Fraction& other) const;
        bool operator<=(const Fraction& other) const;
        bool operator>=(const Fraction& other) const;
        bool operator!=(const Fraction& other) const;
        bool operator==(const Fraction& other) const;
        void print(std::ostream& out) const;
        void read(std::istream& in);

        Fraction inverse() const;
        // ...
    private:
        int numerator;
        int denominator;
        int gcd(int a, int b);
};

Fraction operator+(int n, const Fraction& f);
Fraction operator*(int n, const Fraction& f);
Fraction operator-(const Fraction& f);
Fraction operator-(int n, const Fraction& f);
Fraction operator/(int n, const Fraction& f);
bool operator<(int n, const Fraction& f);
bool operator>(int n, const Fraction& f);
bool operator>=(int n, const Fraction& f);
bool operator<=(int n, const Fraction& f);
bool operator!=(int n, const Fraction& f);
bool operator==(int n, const Fraction& f);
std::ostream& operator<<(std::ostream& out, const Fraction& f);
std::istream& operator>>(std::istream& in, Fraction& f);



#endif // !FRA_H
