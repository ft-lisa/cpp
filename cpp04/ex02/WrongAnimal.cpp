#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
        std::cout << "Construction de la classe WrongAnimal" << std::endl;
}
WrongAnimal::~WrongAnimal()
{
        std::cout << "Destruction de la classe WrongAnimal" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& Wronganimal)
{
        type = Wronganimal.type;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& Wronganimal)
{
        type = Wronganimal.type;
        return(*this);
}
void WrongAnimal::makeSound() const
{
        std::cout << "salut" << std::endl;
}

std::string WrongAnimal::getType() const
{
        return(type);
}
