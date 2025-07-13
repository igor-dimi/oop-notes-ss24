#include <string>
#include <iostream>
#include <vector>

void f (std::string&& s)
{
    std::string s2 = std::move(s);
}

int main(int argc, char const *argv[])
{
    
    std::string s = "data";
    f(std::move(s));
    // std::vector<std::string> coll;
    // coll.push_back(std::move(s));
    std::cout << s << std::endl;
    std::string s2 = std::move(s);
    std::cout << s << std::endl;
    return 0;
}
