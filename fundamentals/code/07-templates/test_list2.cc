#include <iostream>
#include "list.hh"
#include <string>

int main(int argc, char const *argv[])
{
    List<std::string> names;

    names.push_back("Tom");
    names.push_back("Diana");
    names.push_back("Harry");
    names.push_back("Juliet");

    for (List<std::string>::Iterator pos = names.begin(); pos != names.end(); pos++)
        std::cout << *pos << " ";
    std::cout << std::endl;

    List<std::string>::Iterator pos = names.begin();
    pos++;
    pos++;
    names.insert(pos, "Jennifer");

    for (List<std::string>::Iterator pos = names.begin(); pos != names.end(); pos++)
        std::cout << *pos << " ";
    std::cout << std::endl;

    pos = names.erase(pos);

    for (List<std::string>::Iterator pos = names.begin(); pos != names.end(); pos++)
        std::cout << *pos << " ";
    std::cout << std::endl;

    std::cout << *pos << std::endl;

    pos = names.erase(pos);

    for (List<std::string>::Iterator pos = names.begin(); pos != names.end(); pos++)
        std::cout << *pos << " ";
    std::cout << std::endl;

    pos = names.end();
    pos--;

    for (auto el : names) std::cout << el << " ";
    std::cout << std::endl;

    return 0;
}


