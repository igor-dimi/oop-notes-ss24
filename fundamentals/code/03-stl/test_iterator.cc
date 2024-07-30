#include <list>
#include <vector>
#include <typeinfo>
#include <iostream>

template <typename T> void print(T const& cont)
{
    // auto == typename T::const_iterator
    std::cout << typeid(T).name() << ": ";
    for (auto it = cont.begin(); it != cont.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    std::vector<int> v = {1, 2, 3, 4, 5};
    print(v);
    std::list<int> l = {1, 2, 3, 4};
    print(l);
    return 0;
}
