#include <string>
#include <iostream>

class A {
    public :
        virtual std::string f() const = 0;
        virtual ~A() = default;
};

class B : public A 
{
    public: 
        std::string f() const override {return "hello";}
};

int main(int argc, char const *argv[])
{
    std::cout << B().f() << std::endl;

    // A a;

    B b;
    std::cout << b.f() << std::endl;
    return 0;
}
