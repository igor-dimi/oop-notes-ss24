#include <iostream>
#include <memory>
#include <vector>


class ShapeBase // needed to store shpaes in container
{
    public :
        virtual int NumberOfCorners() = 0;
        virtual ~ShapeBase() = default;
};

template <typename T>
class Shape : public ShapeBase 
{
    public :
        int NumberOfCorners() override 
        {
            return static_cast<T*>(this)->corners();
        }
};

class Circle : public Shape<Circle>
{
    public : 
        int corners() {return 0;}
};

class Square : public Shape<Square>
{
    public :
        int corners() {return 4;}
};

enum class ShapeType {Circle, Square};

std::unique_ptr<ShapeBase> create(ShapeType st)
{
    switch (st) {
        case ShapeType::Circle : return std::make_unique<Circle>();
        case ShapeType::Square : return std::make_unique<Square>();
        default : throw std::invalid_argument("uknowng type");
    };
}

int main(int argc, char const *argv[])
{
    std::vector<std::unique_ptr<ShapeBase>> shapes;
    shapes.push_back(create(ShapeType::Circle));
    shapes.push_back(create(ShapeType::Square));

    for (auto const& el : shapes) std::cout << el->NumberOfCorners() << std::endl;
    return 0;
}
