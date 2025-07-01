#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>


template <typename T, typename F>
void iter(T *ptr, int length, F& fct)
{
        if (ptr == NULL)
                return ;
        for (int i=0; i < length; i++)
        {
                fct(ptr[i]);
        }
}

#endif