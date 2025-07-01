#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>
#include <vector>
#include <list>
#include <cmath>


class Span
{
        public :
                Span(unsigned int N);
                Span(const Span&);
                Span& operator=(const Span&);
                ~Span();

                void addNumber(int num);
                void addNumbers(int num, int times);
                int shortestSpan();
                int longestSpan();

                class TooManyException : public std::exception
                {
                        public:
                                const char* what() const throw();
                };
        private :
                int* _array;
                unsigned int _size;
                unsigned int     _i;

};

#endif