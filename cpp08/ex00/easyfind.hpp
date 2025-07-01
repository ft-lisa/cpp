#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>
#include <vector>
#include <list>

template <typename T>
typename T::iterator easyfind(T& array, int num)
{
        for (typename T::iterator i = array.begin(); i != array.end(); i++)
        {
                if (*i == num)
                        return i;    
        }
        return(array.end());        
}

#endif