#ifndef BAS_H
#define BAS_H
#include <type_traits>
#include <string>
#include <cstring>
template<typename T>
T max(T a, T b) {return b < a ? a : b;}

template<typename T1, typename T2>
auto max2(T1 a, T2 b) -> std::decay_t<decltype(true?a:b)>
{
    return b < a ? a : b;
}

// template<typename RT, typename T1, typename T2>
// RT max2 (T1 a, T2 b) { return b < a ? a : b;}

int max (int a, int b) {return b < a ? a : b;}

template<typename T>
T* max(T* a, T* b) {return *b < *a ? a : b;}

char const* max(char const* a, char const* b)
{return std::strcmp(b, a) < 0 ? a : b;}

#endif // !BAS_H

