#include "Zombie.hpp"

Zombie::Zombie()
        : nameZombie("default")
{}
Zombie::~Zombie() 
{
        std::cout << "Destruction de " << nameZombie << std::endl;
}

void Zombie::set_name(std::string name)
{
        nameZombie = name;
}

void Zombie::announce()
{
        if (nameZombie.empty())
        {
                std::cerr << "Error \n The zombie has no name" << std::endl;
                return ;
        }
        std::cout << nameZombie << ": BraiiiiiiinnnzzzZ..." << std::endl;
}