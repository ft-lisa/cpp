#include "Zombie.hpp"

Zombie::Zombie() :nameZombie_("default") {}
Zombie::~Zombie() 
{
        std::cout << "Destruction de " << nameZombie_ << std::endl;
}

void Zombie::SetName(std::string name)
{
        nameZombie_ = name;
}

void Zombie::announce()
{
        if (nameZombie_.empty())
        {
                std::cerr << "Error \n The zombie has no name" << std::endl;
                return ;
        }
        std::cout << nameZombie_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}