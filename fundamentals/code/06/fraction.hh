#ifndef FRA_H
#define FRA_H

#include <iostream>

class Fraction
{
    public: 
        Fraction(int n, int d);
        Fraction(int n);
        Fraction operator+(Fraction other) const;
        Fraction operator-(Fraction other) const;
        Fraction operator*(Fraction other) const;
        Fraction operator/(Fraction other) const;
        bool operator<(Fraction other) const;
        bool operator>(Fraction other) const;
        bool operator<=(Fraction other) const;
        bool operator>=(Fraction other) const;
        bool operator!=(Fraction other) const;
        bool operator==(Fraction other) const;
        void print(std::ostream& out) const;
        void read(std::istream& in);

        Fraction inverse() const;
        // ...
    private:
        int numerator;
        int denominator;
        int gcd(int a, int b);
};

Fraction operator+(int n, Fraction f);
Fraction operator*(int n, Fraction f);
Fraction operator-(Fraction f);
Fraction operator-(int n, Fraction f);
Fraction operator/(int n, Fraction f);
bool operator<(int n, Fraction f);
bool operator>(int n, Fraction f);
bool operator>=(int n, Fraction g);
bool operator<=(int n, Fraction g);
bool operator!=(int n, Fraction g);
bool operator==(int n, Fraction g);
std::ostream& operator<<(std::ostream& out, Fraction f);
std::istream& operator>>(std::istream& in, Fraction f);



#endif // !FRA_H
