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


                int getRawBits() const;
                void setRawBits(int const raw);
                float toFloat() const;
                int toInt() const;
        private:
                int value_;
                const static int bit_ = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);

#endif