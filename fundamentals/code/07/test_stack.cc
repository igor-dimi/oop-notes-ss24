// #include "stack1.hh"
// #include "stack3.hh"
#include <iostream>
#include <string>
#include <utility>
#include <deque>
#include "stacknontype.hh"

struct ValueWithComment {
    std::string value;
    std::string comment;
};

int main(int argc, char const *argv[])
{
    // Stack<int> intStack;
    // Stack<std::string> stringStack;
    // std::pair<int, int> p{3, 7};

    // intStack.push(7);
    // std::cout << intStack.top() << '\n';

    // stringStack.push("hello");
    // stringStack.push("world");
    // std::cout << stringStack.top() << '\n';
    // intStack.push(11);
    // stringStack.pop();
    // intStack.printOn(std::cout);
    // std::cout << std::endl;
    // stringStack.printOn(std::cout);
    // std::cout << std::endl;
    // std::cout << stringStack << intStack << std::endl;

    // Stack<double, std::deque<double>> dblStack;

    // dblStack.push(42.42);
    // std::cout << dblStack.top() << '\n';
    // dblStack.pop();

    // Stack intStack2(3);
    // std::cout << intStack2 << std::endl;
    // std::vector iv {3, 4, 5};
    // for (auto el : iv) std::cout << el << " ";
    // std::cout << std::endl;
    // Stack stringStack2 {"hello"};
    // stringStack2.push("world");
    // std::cout << stringStack2 << std::endl;

    // ValueWithComment vc {"hey", "there"};
    // std::cout << vc.comment << " " << vc.value << std::endl;

    Stack<int, 20> int20Stack;
    Stack<int, 40> int40Stack;
    Stack<std::string,40> stringStack;
    Stack<int, 20u> intStack02;

    int20Stack.push(7);
    std::cout << int20Stack.top() << '\n';
    stringStack.pop();
    auto size1 = intStack02.size();
    


    return 0;
}
