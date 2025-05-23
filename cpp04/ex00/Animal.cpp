#include "Animal.hpp"

Animal::Animal()
{
        std::cout << "Construction de la classe Animal" << std::endl;
}
Animal::~Animal()
{
        std::cout << "Destruction de la classe Animal" << std::endl;
}
Animal::Animal(const Animal& animal)
{
        type = animal.type;
}
Animal& Animal::operator=(const Animal& animal)
{
        type = animal.type;
        return(*this);
}
void Animal::makeSound() const
{
        std::cout << "make a sound" << std::endl;
}

std::string Animal::getType() const
{
        return(type);
}
