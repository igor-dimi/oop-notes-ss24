#include <iostream>

// void print(){}

// additional class template
template<typename T>
class AddSpace
{
    private :
        T const& ref; // refer to argument passed in constructor
    public :
        AddSpace(T const& r) : ref(r) {}
        friend std::ostream& operator<< (std::ostream& os, AddSpace<T> s) {
            return os << s.ref << ' ';
        }
};

// template<typename T, typename... Types>
// void print (T firstArg, Types... args)
// {
//     std::cout << firstArg << '\n';
//     print(args...);
// }

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int i = 0) : value(i), left(nullptr), right(nullptr) {}
};
// template<typename... Types>
// void print(Types const&... args)
// {
//     (std::cout << ... << args) << '\n';
// }

template<typename... Args>
void print(Args... args) {
    (std::cout << ... << AddSpace(args)) << '\n';
}
int main(int argc, char const *argv[])
{
    print("hey", 3, 3.0);
    return 0;
}
