#ifndef FUNDEFS
#define FUNDEFS

#include <cmath>
#include <array>


// non-type template parameters
template<typename T, int n>
struct Vector
{
    static constexpr int dim = n;
    T vals[n];
};


//template-template parameters
template <template <typename T, int n> class V, typename T, int n>
T squaredNorm(const V<T, n> &vec)
{
    T sum = 0;
    for (int i = 0; i < n; i++) 
        sum += vec.vals[i] * vec.vals[i];
    return sum;
}

template <typename T, int n> 
T squaredNorm(Vector<T, n> &vec)
{
    T sum = 0;
    for (int i = 0; i < n; i++) sum += vec.vals[i] * vec.vals[i];
    return sum;
}

// default template parameters P:50
template <typename T, int n, int m = n> struct Matrix
{
    static constexpr int dim1 = n;
    static constexpr int dim2 = m;
    T vals[n * m];
};

// renaming types p: 51
typedef unsigned long long int ull;
ull a = 12345678901234567890u;


template <typename S, typename T>
struct GeneralizedPair
{
    S s;
    T t;
};

typedef GeneralizedPair<Vector<double, 3>, Vector<double, 2>> VecPair3D2D;

// classes and structs p: 53
struct Vector2D
{
    std::array<double, 2> vec;

    double norm() const
    {
        return std::sqrt(vec[0] * vec[0] + vec[1] * vec[1]);
    }
};


// access specifiers p: 54
struct BankAccount
{
    friend class Customer;

    private: 
    double balance = 0.0;
};

class Customer
{
    BankAccount account;
    public:
    void Deposit(double amount) 
    {account.balance += amount;}

    double GetBalance() const {return account.balance;}
};

// constructors p: 56
struct Vector3D 
{
    std::array<double, 3> vec;

    Vector3D() : vec{0, 0, 0} {};
    Vector3D(const Vector3D &v) : vec{v.vec} {}
    Vector3D(Vector3D &&v) noexcept : vec{std::move(v.vec)} {}

    Vector3D(double a, double b, double c) : vec{a, b, c} {};


};


template <typename T>
class Counter{
    private:
    static T count;
    public:
    void increment() {++count;}
    T get() {return count;}
};

#endif // !FUNDEFS