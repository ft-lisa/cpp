#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>
#include <cmath>

class Fixed
{
        public:
                Fixed();
                Fixed(const int value);
                Fixed(const float value);
                Fixed (const Fixed&);
                Fixed &operator=(const Fixed&);
                ~Fixed();

                Fixed operator-(const Fixed& b);
                Fixed operator/(const Fixed& b);
                bool operator<=(const Fixed& b);
                bool operator>=(const Fixed& b);
                Fixed operator*(const Fixed& b);
                bool operator!=(const Fixed& b);
                Fixed operator+(const Fixed& b);
                bool operator==(const Fixed& b);
                bool operator<(const Fixed& b);
                bool operator>(const Fixed& b);

                Fixed operator++(int);
                Fixed operator++();
                Fixed operator--(int);
                Fixed operator--();


                int getRawBits() const;
                void setRawBits(int const raw);
                float toFloat() const;
                int toInt() const;
                static const Fixed& max(const Fixed& a, const Fixed& b);
                static Fixed& max(Fixed& a, Fixed& b);
                static const Fixed& min(const Fixed& a, const Fixed& b);
                static Fixed& min(Fixed& a, Fixed& b);
        private:
                int value_;
                const static int bit_ = 8;

};


std::ostream& operator<<(std::ostream& out, const Fixed& obj);

#endif