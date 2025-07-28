#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <chrono>
#include <memory>
#include <vector>

using namespace std::chrono;
typedef microseconds ms;

class B
{
    public :
        virtual std::string foo() {return "base";}
};

class D : public B 
{
    public :
        std::string foo() override {return "derived";}
};


int main(int argc, char const *argv[])
{
    int size = 100000;
    std::vector<std::unique_ptr<B>> poly(size);
    std::generate(poly.begin(), poly.end(),[]() {
        return std::make_unique<D>();
    });

    std::vector<D> nopoly(size);
    std::generate(nopoly.begin(), nopoly.end(), []() {
        return D();
    });

    auto t0 = steady_clock::now();
    for (const auto &b : poly) b->foo();

    auto t1 = steady_clock::now();
    for (auto &d : nopoly) d.foo();

    auto t2 = steady_clock::now();

    ms dt1 = duration_cast<ms>(t1 - t0);
    ms dt2 = duration_cast<ms>(t2 - t1);

    double s  = (double)dt1.count() / (double)dt2.count();

    std::cout << "with poly: " << dt1.count() << std::endl;;
    std::cout << "no poly: " << dt2.count() << std::endl;;
    std::cout << "speed up: " << s << std::endl;

    return 0;
}
