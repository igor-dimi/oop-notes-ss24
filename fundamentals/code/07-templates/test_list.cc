#include <list>
#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::list<std::string> names;
    names.push_back("Tom");
    names.push_back("Diana");
    names.push_back("Harry");
    for (auto el : names) std::cout << el << " ";
    std::cout << std::endl;
    // std::list<std::string>::iterator pos = names.begin();
    auto pos = names.begin();
    pos++;
    std::cout << *pos << std::endl;
    pos++;
    std::cout << *pos << std::endl;
    *pos = "Romeo";
    std::cout << *pos << std::endl;
    pos = names.begin();
    names.insert(pos, "Marry");
    for (auto el : names) std::cout << el << " ";
    std::cout << std::endl;
    std::cout << *names.begin() << std::endl;
    names.insert(names.end(), "Juliet");
    for (const auto& el : names) std::cout << el << " ";
    std::cout << std::endl;
    names.push_front("Sally");
    for (const auto& el : names) std::cout << el << " ";
    std::cout << std::endl;
    std::cout << names.size() << std::endl;
    auto it = names.begin();
    it++;
    names.insert(it, "Andrew");
    for (const auto& el : names) std::cout << el << " ";
    std::cout << std::endl;
    std::cout << *it << std::endl;
    it = names.erase(it);
    for (const auto& el : names) std::cout << el << " ";
    std::cout << std::endl;
    std::cout << *it << std::endl;
    names.pop_front(); names.pop_back();
    for (const auto& el : names) std::cout << el << " ";
    std::cout << std::endl;
    auto it2 = names.end();
    std::cout << *--it2 << std::endl;
    return 0;
}
