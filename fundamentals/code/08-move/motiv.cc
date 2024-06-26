#include <string>
#include <vector>
#include <iostream>
#include <cstring>

class String {
    private : 
        int len;
        char* data;

    public :
        String (String const& s) : len{s.len} {
            if (len > 0) {
                data = new char[len + 1];
                std::memcpy(data, s.data, len+1);
            }
        }
        String (String&& s);
};

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

    std::string s = "data";
    std::cout << s << std::endl;
    std::string s2;

    return 0;
}

// syntax for move semantics:
// void push_back(T&& elem);

// rvalue reference => && 