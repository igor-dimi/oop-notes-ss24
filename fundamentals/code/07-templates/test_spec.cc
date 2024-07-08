#include <iostream>
#include <string>

template <typename T> 
struct Template2String
{
    static std::string print(T const& data)
    {
        return "no specialization for type";
    }
};

template <>
struct Template2String<int>
{
    static std::string print(int const& data)
    {
        return "specialized for int: " + std::to_string(data);
    }
};

template <>
struct Template2String<std::string>
{
    static std::string print(std::string const& data)
    {
        return "specialized for string: " + data;
    }
};

template <typename T> std::string print( T const& data)
{
    return Template2String<T>::print(data);
}




int main(int argc, char const *argv[])
{
    std::cout << print(3.13) << std::endl;
    std::cout << print(42) << std::endl;
    std::cout << print(print(42)) << std::endl;
    return 0;
}
