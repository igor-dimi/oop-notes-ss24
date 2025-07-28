#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <chrono>
#include <utility>
#include <string>

using namespace std::chrono;
using ms = microseconds;

class A
{
   public:
    A() {x = 0;}
    A(int _x) : x(_x) {}
    virtual std::string print() const {return "base";} 
   private :
    int x;
};

class B : public A
{
    public :
        B() : y(0) {}
        B(int _x, int _y) : A(_x), y(_y) {}
        std::string print() const override {return "derived"; }
        void foo() {return;}
    private :
        int y;
};

int main(int argc, char const *argv[])
{
    B b;
    A a = b;
    a.print();
    b.print();
    A& ar = b;
    ar.print();
    A* ap = &b;
    ap->print();
    A().print();
    B().print();

    A* ap2 = new B;
    ap->print();

    // std::vector<std::unique_ptr<A>> vec1(10000000);
    // std::generate(vec1.begin(), vec1.end(), [] {return std::make_unique<B>();});

    // std::vector<B> vec2(10000000);
    // std::generate(vec2.begin(), vec2.end(), [] {return B();});

    // auto t0 = std::chrono::steady_clock::now(); 
    // for (const auto& b : vec1) b->print();
    // auto t1 = std::chrono::steady_clock::now(); 
    // for (const auto& d : vec2) d.print();
    // auto t2 = std::chrono::steady_clock::now(); 

    // ms dt1 = duration_cast<ms>(t1 - t0);
    // ms dt2 = duration_cast<ms>(t2 - t1);

    // double s = (double) dt1.count() / (double) dt2.count();

    // std::cout << "with poly: " << dt1.count() << std::endl;
    // std::cout << "w/out poly: " << dt2.count() << std::endl;

    // std::cout << "speed-up: " << s << std::endl;


    A* ap3 = new B(b); 
    A* ap4 = ap3;
    A a4 = *ap3;

    A* ap5 = new A(*ap3);

    std::cout << ap4->print() << std::endl;
    std::cout << ap5->print() << std::endl;

    
    
    return 0;
    
}
