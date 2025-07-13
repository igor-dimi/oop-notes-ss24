#include <iostream>

template <typename S, typename T = S> 
class Pair
{
    public:
        Pair (T const& _t, S const& _s) :s(_s), t(_t) {}
        const T& get_t() const {return t;}
        const S& get_s() const {return s;}
    private :
        S s;
        T t;
    
};

// specializing when the types are pointers:
template <typename S, typename T> 
class Pair<S*, T*>
{
    private :
        S* s;
        T* t;
    public :
        Pair(S* _s, T* _t) : s(_s), t(_t) {}
        const S& get_s() const {return *s;}
        const T& get_t() const {return *t;}
        ~Pair()
        {
            delete t;
            delete s;
        }

};


int main(int argc, char const *argv[])
{
    Pair<int> pp1(42, 43);
    std::cout << "pp1 s: " << pp1.get_s() << std::endl;
    std::cout << "pp1 t: " << pp1.get_t() << std::endl;

    Pair<int*, double*> pp2(new int(42), new double(43.0));
    std::cout << "pp2 s: " << pp2.get_s() << std::endl;
    std::cout << "pp2 t: " << pp2.get_t() << std::endl;

    return 0;
}
