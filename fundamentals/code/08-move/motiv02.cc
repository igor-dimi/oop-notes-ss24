#include <string>
#include <vector>
#include <iostream>

std::vector<std::string> createAndInsert()
{
    std::vector<std::string> coll;
    coll.reserve(3);
    std::string s = "data";

    coll.push_back(s);
    coll.push_back(s + s);
    coll.push_back(std::move(s));

    return coll;
}

template <typename T>
void print(std::ostream &os, std::vector<T> const& vec)
{
    for (auto el :  vec) os << el << " ";
}

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> const& vec)
{
    print(os, vec);
    return os;
}

int main(int argc, char const *argv[])
{
    std::vector<std::string> v;
    v = createAndInsert();
    std::cout << v << std::endl;
    return 0;
}