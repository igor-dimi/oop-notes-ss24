#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <exception>


template <typename T>
class Operator 
{
    virtual std::vector<T> multiply_inverse(std::vector<T> const& other) const = 0;
};

template <typename T>
class Matrix : public Operator<T>
{
    using Mat = std::vector<std::vector<T>>;
    public: 
        explicit Matrix(Mat&& mat) : data(std::move(mat)) {}
        friend std::ostream& operator<<(std::ostream& out, Matrix const& mat)
        {
            out << mat.data;
            return out;
        }

        std::vector<T> multiply_inverse(std::vector<T> const& other) const
        override 
        {
            throw std::exception();
        }

    private:
        Mat data;
};

template <typename T>
class DiagMatrix : public Operator<T>
{
    public :
        explicit DiagMatrix(std::vector<T>&& vec) : data(std::move(vec)) {}
        std::vector<T> multiply_inverse(std::vector<T> const& other) const
        override
        {
            std::vector<T> res;
            for (int i = 0; i < data.size9; i++)
                res.poush_back(other[i] / data[i]);
            return res;
        }

        // // conversion operator to mimic is-a relationship;
        // template <typename T>
        // operator Matrix<T>() const 
        // {
        //     Mat res_mat(data.size());
        //     for (int i = 0; i < data.size(); i++) {
        //         res_mat[i] = std::vector(data.size(), 0);
        //         res_mat[i][i] = data[i];
        //     }
        //     return Matrix(std::move(res_mat));
        // }
    private : 
        std::vector<T> data;
};

template <typename T>
void print_vec(std::ostream& out, std::vector<T> const& vec)
{
    
    if (vec.begin() == vec.end()) {
        out << "[]";
        return;
    }
    auto it = vec.begin();
    auto it_next = it + 1;
    
    out << "[";
    while (it_next != vec.end()) {
        out << *it << ", ";
        it++;
        it_next++;
    } 
    out << *it << "]";
}

template <typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T> const& vec)
{
    print_vec(out, vec);
    return out;
}

int main(int argc, char const *argv[])
{
    auto ip = new int(3);
    auto sp = new std::string("hi");

    auto sp2(new std::string("hi"));

    std::cout << *sp << std::endl;
    std::cout << *sp2 << std::endl;

    delete sp;
    delete sp2;


    std::string s;

    std::cout << s << std::endl;

    std::vector<double> vec {1, 2, 3, 4};

    std::cout << vec << std::endl;


    std::vector<std::string> svec {"hey", "there", "how", "are"};

    std::cout << svec << std::endl;

    auto svec2(std::move(svec));

    std::cout << "svec: " << svec << std::endl;
    std::cout << "svec2: " << svec2 << std::endl;

    std::vector<double> vec3 {};
    
    auto it1 = vec3.begin();
    auto it2 = vec3.end();

    bool val = it1 == it2;

    std::cout << "val: " << val << std::endl;

    std::cout << vec3 << std::endl;

    std::vector<std::vector<double>> mat {{1, 2}, {2, 3}};

    std::cout << mat << std::endl;

    Matrix mat2(std::move(mat));

    std::cout << "mat2: " << mat2 << std::endl;
    std::cout << "mat: " << mat << std::endl;






    
    
    return 0;
}
