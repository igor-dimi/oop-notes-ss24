#include <iostream>
#include <string>
#include <vector>

template <typename T>
struct DependentB
{
    protected :
        explicit DependentB(T const& _data) : data(_data) {}
        T data;
    public :
    std::string print() {return std::to_string(data);}
};

template <typename T> 
class Derived : public DependentB<T>
{
    public :
        explicit Derived (T const& d)  : DependentB<T>(d) {}
};

template <typename T>
struct GenericContainer
{
    std::vector<T> values;
    void insert(T value) {values.push_back(value);}
};

struct DoubleContainer : GenericContainer<double>
{
    double Value(int i ){return values[i];}
};

struct IntContainer : GenericContainer<int>
{
    int Value(int i) {return values[i];}
};

int main(int argc, char const *argv[])
{
    // this is a comment ... and you'all should know 
    Derived d(42);
    std::cout << d.print() << std::endl;
    DoubleContainer dc;
    dc.insert(2.5);
    IntContainer ic;
    ic.insert(2.5);

    std::cout << "dc: " << dc.Value(0) << std::endl;
    std::cout << "ic: " << ic.Value(0) << std::endl;
    return 0;

}
