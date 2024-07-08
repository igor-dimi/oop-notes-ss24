#include <iostream>
#include <memory>
#include <vector>


struct ShapeBase
{
    // needed to store different shapes in container
    virtual int NumberOfCorners() = 0;
    virtual ~ShapeBase() = default;
};

template <typename Derived>
struct Shape : ShapeBase
{
    int NumberOfCorners() override 
    {
        auto derived = static_cast<Derived*> (this);
        return derived->CornerImplementation();
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

enum class ShapeType {Circle, Square};

struct Factory
{
    template <typename T>
    std::unique_ptr<T> create()
    {
        return std::make_unique<T>();
    }

    std::unique_ptr<ShapeBase> create(ShapeType type)
    {
        switch (type) {
            case ShapeType::Circle: return create<Circle>();
            case ShapeType::Square: return create<Square>();
            default : throw std::invalid_argument("Unknown Type");
        }
    }
};


int main(int argc, char const *argv[])
{
    std::vector<std::unique_ptr<ShapeBase>> shapes;
    shapes.push_back(Factory().create(ShapeType::Circle));
    shapes.push_back(Factory().create(ShapeType::Square));
    std::cout << shapes[0]->NumberOfCorners() << std::endl;
    std::cout << shapes[1]->NumberOfCorners() << std::endl;
    return 0;
}
