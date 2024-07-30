#include <iostream>


template <typename T>
class B // base class
{
    public :
        void interface()
        {
            return static_cast<T*>(this)->implementation();
        }
};

class C : public B<C> // C derived from B utilizing CRTP
{
    public :
        void implementation()
        {
            std::cout << "I am C" << std::endl;
        }
};


class D : public B<D> // D derived from B utilizing CRTP
{
    public :
        void implementation()
        {
            std::cout << "I am D" << std::endl;
        }
};

template <typename T>
void CallInterface(B<T>& br)
{
    br.interface();
}

int main(int argc, char const *argv[])
{
    /* code */

    C c;
    D d;
    CallInterface(c);
    CallInterface(d);

    return 0;
}
