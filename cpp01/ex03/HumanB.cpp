#include "HumanA.hpp"

HumanB::HumanB(std::string name) : Weapon_(NULL), name_(name)
{
}
HumanB::~HumanB() {}

void HumanB::attack()
{
        if (Weapon_ == NULL)
        {
                std::cout << name_ << " attacks with their hands" << std::endl;
                return ;
        }
        std::cout << name_ << " attacks with their " << Weapon_->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& Weapon)
{
        Weapon_ = &Weapon;
}