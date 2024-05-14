#include <iostream>

int main(int argc, char const *argv[])
{
    int n;
    std::cin >> n;
    int i = 0;
    switch(n % 2) {
        case 0 :
        do {
            ++i;
            --n;
            case 1: ++i;
        } while (--n > 0);
    }
    std::cout << i << std::endl;;
    return 0;
}
