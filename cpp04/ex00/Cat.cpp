#include "Cat.hpp"

Cat::Cat() : Animal()
{
        type = "Cat";
        std::cout << "Construction de la classe Cat" << std::endl;
}
Cat::~Cat()
{
        
        std::cout << "Destruction de la classe Cat" << std::endl;
}
Cat::Cat(const Cat& Cat)
{
        type = Cat.type;
}
Cat& Cat::operator=(const Cat& Cat)
{
        type = Cat.type;
        return(*this);
}
void Cat::makeSound() const
{
        std::cout << "miaou" << std::endl;
}