#include "Cat.hpp"

Cat::Cat() : Animal()
{
        _brain = new Brain();
        type = "Cat";
        std::cout << "Construction de la classe Cat" << std::endl;
}
Cat::~Cat()
{
        delete _brain;
        std::cout << "Destruction de la classe Cat" << std::endl;
}
Cat::Cat(const Cat& Cat)
{
        _brain = new Brain(*Cat._brain);
        type = Cat.type;
}
Cat& Cat::operator=(const Cat& Cat)
{
        delete _brain;
        _brain = new Brain(*Cat._brain);
        type = Cat.type;
        return(*this);
}
void Cat::makeSound() const
{
        std::cout << "miaou" << std::endl;
}

void Cat::setIdeas(std::string str, int i)
{
    _brain->setIdeas(str, i);
}

std::string Cat::getIdeas(int i)
{
    return(_brain->getIdeas(i));
}