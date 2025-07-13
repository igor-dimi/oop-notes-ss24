#include <iostream>
#include <string>

struct Animal
{
    std::string noise;
    explicit Animal(std::string&& _noise) : noise(std::move(_noise)) {}
    virtual std::string get_noise() const {return noise;}
};

int main(int argc, char const *argv[])
{
    std::cout << "hello" << std::endl;
    return 0;
}
