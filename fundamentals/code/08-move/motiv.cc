#include <string>
#include <vector>
#include <iostream>

std::vector<std::string> create_and_insert()
{
    std::vector<std::string> strings;
    strings.reserve(3);
    std::string s = "data";

    strings.push_back(s);
    strings.push_back(s + s);
    strings.push_back(std::move(s)); // we no longer need value of s

    return strings;
}

int main(int argc, char const *argv[])
{
    
    std::vector<std::string> v;
    v = create_and_insert();
    for (auto el : v) std::cout << el << " " << std::endl;
    return 0;
}
