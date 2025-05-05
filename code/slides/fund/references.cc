#include <iostream>

double &ProcessDataRef()
{
    static double data = 3; // shared across calls
    return data;
}

int main(int argc, char const *argv[])
{
    double data = 4;
    ProcessDataRef() = 5; // ProcessDataRef() is an lvalue
    std::cout << "data in main: " << data << std::endl << "data in ProcessDataRef: " << ProcessDataRef() << std::endl;
    return 0;
}
