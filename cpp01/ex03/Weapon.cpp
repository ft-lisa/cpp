
#include "HumanA.hpp"

Weapon::Weapon(std::string name) :type_(name)
{
}

Weapon::~Weapon() {}

std::string Weapon::getType()
{
        // ou pointer 
        std::string &value = type_;
        return(value);
}
void Weapon::setType(std::string str)
{
        type_ = str;
}