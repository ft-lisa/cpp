#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>
#include "Weapon.hpp"
#include "HumanA.hpp"

class HumanB
{
        public:
                HumanB(std::string name);
                ~HumanB();
                void setWeapon(Weapon& Weapon);
                void attack();
        private:
                Weapon* Weapon_;
                std::string name_;
};

#endif