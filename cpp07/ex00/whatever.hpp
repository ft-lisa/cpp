#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>

template <typename T>
void swap(T& a, T& b)
{
        T c;

        c = b;
        b = a;
        a = c;
}

template <typename T>
T min(T a, T b)
{
        if (a < b)
                return a;
        return b;
}

template <typename T>
T max(T a, T b)
{
        if (a > b)
                return a;
        return b;
}

#endif