#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>

class Weapon
{
        public:
                Weapon(std::string name);
                ~Weapon();
                std::string getType();
                void setType(std::string str);
        private:
                std::string type_;
};

#endif