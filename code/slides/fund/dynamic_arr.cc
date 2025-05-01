#include <iostream>
#include <vector>
    
int main(int argc, char const *argv[])
{
    std::vector<int> arr = {1, 2, 3};
    for (int i = 0; i < arr.size(); i++) arr[i] = i;
    for (int i = 0; i < arr.size(); i++) std::cout << arr[i] << " ";
    std::cout << std::endl;

    arr[10] = 3;
    for (int i = 0; i < arr.size(); i++) std::cout << arr[i] << " ";
    std::cout << std::endl;
    std::cout << "1) " << arr.size() << std::endl;
    std::cout << "2) " << arr[10] << std::endl;



    std::cout << "3.0) capacity before push back: " << arr.size() << std::endl;
    arr.push_back(10);
    std::cout << "3) capacity after push back: " << arr.size() << std::endl;
    for (int i = 0; i < arr.size(); i++) std::cout << arr[i] << " ";
    std::cout << std::endl;
    std::cout << "4) " << arr.size() << std::endl;
    std::cout << "5) " << arr[5] << std::endl;

    std::vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
        std::cout << "Size: " << v.size() << ", Capacity: " << v.capacity() << "\n";
    }

    for (auto it = v.begin(); it != v.end(); ++it) std::cout << *it << " ";
    std::cout << std::endl;

    return 0;
}
