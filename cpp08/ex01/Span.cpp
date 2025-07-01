#include "Span.hpp"

Span::Span(unsigned int N) : _i(0)
{
        _array = new int[N];
        _size = N;
}

Span::Span(const Span& other) : _i(0)
{
        _size = other._size;
        _array = new int[_size];
        _i = other._i;
        for (unsigned int i = 0; i <= _i; i++)
        {
                _array[i] = other._array[i];
        }
}
Span& Span::operator=(const Span& other)
{
        if(this != &other)
        {
                delete _array;
                _size = other._size;
                _i = other._i;
                _array = new int[_size];
                for (unsigned int i = 0; i <= _i; i++)
                {
                        _array[i] = other._array[i];
                }
        }
        return (*this);
}
Span::~Span()
{
        delete []_array;
}

const char* Span::TooManyException::what() const throw() 
{
    return "Too many numbers";
}

void Span::addNumber(int num)
{
        if (_i >= _size)
                throw TooManyException();
        else
        {
                 _array[_i] = num;
                 _i++;
        }
}
void Span::addNumbers(int num, int times)
{
        for (int i = 0; i < times; i++)
        {
                if (_i >= _size)
                        throw TooManyException();
                else
                {
                        _array[_i] = num;
                        _i++;
                }
        }
}

int Span::shortestSpan()
{
        int shortSpan = 2147483647;
        for(unsigned int i = 0; i < _i; i++)
        {
                for(unsigned int j = i + 1; j < _i; j++)
                {
                        if (abs(_array[i] - _array[j]) < shortSpan)
                        {
                                shortSpan = abs(_array[i] - _array[j]);
                        }
                                
                }
        }
        return shortSpan;
}
int Span::longestSpan()
{
        int smaller = 2147483647;
        int bigger = 0;

        for(unsigned int i = 0; i < _i; i++)
        {
                if (_array[i] < smaller)
                        smaller = _array[i];
                if (_array[i] > bigger)
                        bigger = _array[i];
        }
        return (bigger - smaller);
}