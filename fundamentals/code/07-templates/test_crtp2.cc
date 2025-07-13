#include <iostream>
#include <string>

template <typename T>
struct Base
{
    std::string interface()
    {
        return static_cast<T*>(this)->implementation();
    }
};

struct D1 : public Base<D1>
{
    std::string implementation()
    {
        return "D1";
    }
};

struct D2 : public Base<D2>
{
    std::string implementation()
    {
        return "D2";
    }
};


template<typename T>
std::string call_interface(Base<T>& b)
{
    return b.interface();
}

int main(int argc, char const *argv[])
{
    D1 d1;
    D2 d2;

    std::cout << call_interface(d1) << std::endl;
    std::cout << call_interface(d2) << std::endl;
    return 0;
}
