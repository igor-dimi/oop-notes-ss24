#include "myvect.hh"
#include <stdexcept>


Myvect::Myvect() : data(new int[4]), capacity(4), length(0) {}

Myvect::~Myvect() {delete[] data;}


void Myvect::push_back(int value)
{
    if (length == capacity) resize();
    data[length++] = value;
}

int Myvect::get(std::size_t index) const
{
    if (index >= length) throw std::out_of_range("Index out of range");
    return data[index];
}

std::size_t Myvect::size() const {return length;}

void Myvect::resize() {
    capacity *= 2;
    int* new_data = new int[capacity];
    for (std::size_t i = 0; i < length; i++)  new_data[i] = data[i];
    delete[] data;
    data = new_data;
}