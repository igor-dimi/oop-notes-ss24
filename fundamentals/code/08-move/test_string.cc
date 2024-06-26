#include "string.h"
#include <vector>

int main(int argc, char const *argv[])
{
    String s1("Ann");
    String s2("Fred");
    s1 = s2;
    String s3 = s1;
    String s4 = s1.substr(1,10);


    std::cout << s1 << std::endl;
    std::cout << s4 << std::endl;

    String s5 = std::move(s1);
    std::cout << "s5: " << s5 << std::endl;
    std::cout << "s1: " << s1 << std::endl;
    
    int x{23};
    int y = std::move(x);
    
    std::cout << "y: " << y << std::endl;
    std::cout << "x: " << x << std::endl;

    int z = y;
    std::cout << "z: " << z << std::endl;


    {
        std::vector<String> vec;
        String s{"hey"};
        vec.push_back(std::move(s));
        for (auto el : vec) std::cout << el << " ";
        std::cout << std::endl;
        std::cout << "s: " << s << std::endl;

    }

    {
        const String s("hello world!");
        String s2 = std::move(s);
        std::cout << "s2: " << s2 << std::endl;
        std::cout << "s: " << s << std::endl;
    

    }
    {
        String s("good-bye world!");
        String s2 = std::move(s);
        std::cout << "s2: " << s2 << std::endl;
        std::cout << "s: " << s << std::endl;
    

    }


    return 0;
}
