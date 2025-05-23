#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>
#include <string.h>



class Harl
{
        public:
                void complain(std::string level);

        private:
                void debug();
                void info();
                void warning();
                void error();
                typedef void (Harl::*Func)();
};

#endif