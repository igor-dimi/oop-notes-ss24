#include <iostream>
#include "pair.hh"

template<typename T>
void print(std::ostream& out, T data[], int size)
{
    int i = 0;
    
    while (i < size - 1) {
        out << data[i] << ", ";
        i++;
    } // size > 0 => i == size - 1

    if (i == size - 1) out << data[i] << std::endl;


}

template<typename T>
Pair<T> minmax(T data[], int size)
{
    T min = data[0];
    T max = data[0];

    for (int i = 1; i < size; i++) {
        if (data[i] < min) min = data[i];
        if (data[i] > max) max = data[i];
    }
    return Pair(min, max);
}


int main(int argc, const char** argv) {
    
    double a[]{1.0, 2.0, 3.0};
    int b[]{1, 2, 3, 4};
    char s1[]{};
    char s2[]{'c'};
    print(std::cout, a, 3);
    print(std::cout, b, 4);
    print(std::cout, s1, 0);
    print(std::cout, s2, 1);

    Pair p1 = minmax(a, 3);
    Pair p2 = minmax(b, 4);
    std::cout << p1.get_first() << " " << p1.get_second() << std::endl;
    std::cout << p2.get_first() << " " << p2.get_second() << std::endl;


    // this is cool if you ask me and that is the thing , 
    // how could you tell me that this is the case you moron,

    




    return 0;
}