#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& Weapon) :Weapon_(Weapon), name_(name)
{
}
HumanA::~HumanA() {}

void HumanA::attack()
{
        std::cout << name_ << " attacks with their " << Weapon_.getType() << std::endl;
}