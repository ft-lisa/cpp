#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
        public :

                ScavTrap(std::string name);
                ~ScavTrap();
                ScavTrap (const ScavTrap& clap);
                ScavTrap& operator=(const ScavTrap& clap);
                void attack(const std::string& target);
                void guardGate();
                
};

#endif