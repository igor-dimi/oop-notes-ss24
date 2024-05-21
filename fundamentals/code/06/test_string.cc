#include <iostream>
#include <string>
#include "string.hh"

int main(int argc, const char** argv) {
    std::string s1 = "hey";
    std::string s2 = "there";
    std::cout << s1 + " " + s2 << std::endl;

    String secretary("Igor");
    String treasurer("Elena");

    secretary = treasurer = secretary;

    return 0;
}