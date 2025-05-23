#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal()
{
        _brain = new Brain();
        type = "Dog";
        std::cout << "Construction de la classe Dog" << std::endl;
}
Dog::~Dog()
{
        delete _brain;
        std::cout << "Destruction de la classe Dog" << std::endl;
}
Dog::Dog(const Dog& Dog)
{
        _brain = new Brain(*Dog._brain);
        type = Dog.type;
}
Dog& Dog::operator=(const Dog& Dog)
{
        delete _brain;
        _brain = new Brain(*Dog._brain);
        type = Dog.type;
        return(*this);
}
void Dog::makeSound() const
{
        std::cout << "wouf" << std::endl;
}

void Dog::setIdeas(std::string str, int i)
{
    _brain->setIdeas(str, i);
}
std::string Dog::getIdeas(int i)
{
    return(_brain->getIdeas(i));
}