#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP


#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>

class ClapTrap
{
        public:

                ClapTrap(std::string name);
                ~ClapTrap();
                ClapTrap(const ClapTrap& clap);
                ClapTrap& operator=(const ClapTrap&);
                void attack(const std::string& target);
                void takeDamage(unsigned int amount);
                void beRepaired(unsigned int amount);
        private:
                std::string     _name;
                int             _pv;
                int             _ep;
                int             _damage;

};

#endif