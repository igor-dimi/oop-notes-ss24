#include <iostream>
#include <numeric>
#include <vector>
#include <ranges>

int main(int argc, char const *argv[])
{
    std::vector<int> v(10);
    std::iota(v.begin(), v.end(), 0);

    for (const auto &el : v) std::cout << el << " ";
    std::cout << std::endl;

    auto even = [](int i) {return i % 2 == 0;};
    for (const auto &el : v | std::views::filter(even)) std::cout << el << " ";
    std::cout << std::endl;

    return 0;
}
