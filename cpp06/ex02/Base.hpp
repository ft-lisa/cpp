#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <stdint.h>
#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>
#include <ctime>

class Base
{
        public :
                Base* generate(void);
                void identify(Base* p);
                void identify(Base& p);
                virtual ~Base();


};

#endif