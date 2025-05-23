#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP


#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>
#include "ClapTrap.hpp"


class FragTrap : public ClapTrap
{
        public :

                FragTrap(std::string name);
                ~FragTrap();
                FragTrap& operator=(const FragTrap& clap);
                FragTrap (const FragTrap& clap);
                void highFivesGuys();        
};

#endif
