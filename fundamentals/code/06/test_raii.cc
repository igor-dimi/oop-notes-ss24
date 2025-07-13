#include <iostream>
#include <string>
#include <vector>


template <typename T> 
class MySmartPointer
{
    private: 
        T* ptr;
    public:
        MySmartPointer() {ptr = new T;}
        ~MySmartPointer() {delete ptr;}

};

class Y
{
    MySmartPointer<int> ptrA;
    MySmartPointer<double> ptrB;
    MySmartPointer<std::string> ptrC;
    MySmartPointer<std::vector<int>> ptrD;

};



int main(int argc, char const *argv[])
{
    try {
        Y y;
    } catch (std::bad_alloc& e) {
        std::cerr << e.what();
    }
    return 0;
}
