#include <iostream>

struct ShapeBase
{
    virtual int NumberOfCorners() = 0;
    virtual ~ShapeBase() = default;
};

template <typename T>
struct Shape : ShapeBase
{
    int NumberOfCorners () override 
    {
        auto this_ptr = static_cast<T*>(this);
        return this_ptr->CornerImplementation();
    }
};


struct Circle : Shape<Circle>
{
    int CornerImplementation() {return 0;}
};

struct Square : Shape<Square> 
{
    int CornerImplementation() {return 4;}
};





int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
