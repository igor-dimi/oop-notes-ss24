#include <iostream>


int main(int argc, char const *argv[])
{
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 10; i++) {
        if (arr[i] % 2 == 0) std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    int arr2[10];
    std::cout << arr << std::endl;
    std::cout << arr2 << std::endl;

    int* arr3 = new int[2];
    arr3[0] = arr3[1] = 1;
    std::cout << "1) " << arr3 << std::endl;
    std::cout << "2) " << arr3[1] << std::endl;
    delete[] arr3;
    std::cout << "3) " << arr3 << std::endl;
    std::cout << "4) " << arr3[0] << " " << arr3[1] << " " << arr3[5] << std::endl;
    arr3 = arr;

    return 0;
}
