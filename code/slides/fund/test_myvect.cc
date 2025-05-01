#include "myvect.hh"
#include <iostream>


int main(int argc, char const *argv[])
{
    Myvect vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    for (std::size_t i = 0; i < vec.size(); i++) 
        std::cout << "Element " << i << ": " << vec.get(i) << "\n";

    return 0;
}
