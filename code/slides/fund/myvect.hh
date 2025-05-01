// myvect.hh
#ifndef MYVECT_HH
#define MYVECT_HH

#include <cstddef>

class Myvect {
    public: 
        Myvect();
        ~Myvect();
        void push_back(int value);
        int get(std::size_t index) const;
        std::size_t size() const;

    private:
        int* data;
        std::size_t capacity;
        std::size_t length;
        void resize();
};

#endif