#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>

template <typename T>
class Array
{
        public :
                Array(): _size(0)
                {
                        _array = NULL;
                        
                }

                Array(unsigned int n) : _size(n)
                {
                        _array = new T[n];
                }

                Array(const Array& other)
                {
                        _size = other._size;
                        _array = new T[_size];
                        for (size_t i=0; i < _size; i++)
                                _array[i] = other._array[i];
                }

                Array& operator=(const Array& other)
                {
                        delete[] _array;
                        _size = other._size;
                        _array = new T[_size];
                        for (size_t i=0; i < _size; i++)
                                _array[i] = other._array[i];
                        return(*this);
                }

                ~Array()
                {
                        delete[] _array;
                }

                T& operator[](unsigned int i)
                {
                        if (i < 0 || i >= _size)
                                throw InvReadException();
                        else
                                return(_array[i]);
                }

                class InvReadException : public std::exception 
                {
                        public:
                                const char* what() const throw()
                                {
                                        return "Invalid read";
                                }
                };

                unsigned int size() const
                {
                        return(_size);
                }

                void fillArray(T n)
                {
                        for(unsigned int i = 0; i < _size; i++)
                        {
                                _array[i] = n; 
                        }
                }
                
        private :
                T* _array;
                size_t _size;
};



#endif