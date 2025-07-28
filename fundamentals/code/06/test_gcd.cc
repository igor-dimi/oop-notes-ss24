#include <iostream>

int gcd(int a, int b)
{
    if (a == 0) return b;
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main(int argc, const char** argv) {
    int a, b;
    std::cin >> a >> b;
    std::cout << gcd(a, b) << std::endl;
    return 0;
}