#include "Dog.hpp"

Dog::Dog() : Animal()
{
        type = "Dog";
        std::cout << "Construction de la classe Dog" << std::endl;
}
Dog::~Dog()
{
        std::cout << "Destruction de la classe Dog" << std::endl;
}
Dog::Dog(const Dog& Dog)
{
        type = Dog.type;
}
Dog& Dog::operator=(const Dog& Dog)
{
        type = Dog.type;
        return(*this);
}
void Dog::makeSound() const
{
        std::cout << "wouf" << std::endl;
}