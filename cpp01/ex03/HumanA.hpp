#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>
#include "HumanB.hpp"
#include "Weapon.hpp"

class HumanA
{
        public:
                HumanA(std::string name, Weapon& Weapon);
                ~HumanA();
                void setWeapon(Weapon weapon);
                void attack();
        private:
                Weapon &Weapon_;
                std::string name_;
};

#include "HumanB.hpp"

#endif