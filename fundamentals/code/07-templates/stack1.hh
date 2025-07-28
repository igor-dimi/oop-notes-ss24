#ifndef STA1_H
#define STA1_H    

#include <vector>
#include <cassert>
#include <iostream>

template<typename T>
class Stack 
{
    private :
        std::vector<T> elems; // elements

    public :
        Stack () = default;
        Stack (T elem) : elems({std::move(elem)}) {}
        void push(T const& elem);
        T pop();
        T const& top() const;
        bool empty() const {return elems.empty();};
        void printOn(std::ostream& strm) const
        {
            for (T const& elem : elems) {
                strm << elem << ' '; 
            }
        }
        friend std::ostream& operator<< (std::ostream& strm, 
                                         Stack<T> const& s)
        {
            s.printOn(strm);
            return strm;
        }
};

template<typename T>
void Stack<T>::push (T const& elem) {elems.push_back(elem);}

template<typename T>
T Stack<T>::pop()
{
    assert(!elems.empty());
    T elem = elems.back();
    elems.pop_back();
    return elem;
}

template<typename T>
T const& Stack<T>::top() const
{
    assert(!elems.empty());
    return elems.back();
}


// template<typename T>
// bool operator== (Stack<T> const& lhs, Stack<T> const& rhs);


#endif // !STA1_H
