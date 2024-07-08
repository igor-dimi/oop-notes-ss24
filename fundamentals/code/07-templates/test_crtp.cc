#include <iostream>
#include <vector>
#include <string>

template <typename T> struct CRTPBase 
{
    std::string interface() 
    {
        return static_cast<T*>(this)->implementation();
    }
};

struct CRTPDerived1 : public CRTPBase<CRTPDerived1>
{
    // warning on function hiding can be ignored
    std::string implementation() {return "CRTPDerived";}
};

struct CRTPDerived2 : public CRTPBase<CRTPDerived2>
{
    // warning on function hiding can be ignored
    std::string implementation() {return "crtp derived 2";}
};


template <typename T>
std::string CallInterface(CRTPBase<T>& base)
{
    return base.interface();
}

int main(int argc, char const *argv[])
{

    CRTPDerived2 d2;
    CRTPDerived1 d1;

    std::cout << CallInterface(d1) << std::endl;
    std::cout << CallInterface(d2) << std::endl;
    return 0;
}
