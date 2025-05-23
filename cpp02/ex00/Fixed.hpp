#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>

class Fixed
{
        public:
                Fixed();
                Fixed (const Fixed&);
                Fixed &operator=(const Fixed&);
                ~Fixed();
                int getRawBits() const;
                void setRawBits(int const raw);
        private:
                int value;
                const static int bit = 8;
};

#endif