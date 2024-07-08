#include <iostream>

enum class COLOR {
    blue = 0,
    red = 1

};

int main(int argc, char const *argv[])
{
    /* code */
    enum COLOR c, c2;
    c = COLOR::blue;
    c2 = COLOR::red;
    return 0;
}
