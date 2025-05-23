#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
        type = "WrongCat";
        std::cout << "Construction de la classe WrongCat" << std::endl;
}
WrongCat::~WrongCat()
{
        std::cout << "Destruction de la classe WrongCat" << std::endl;
}
WrongCat::WrongCat(const WrongCat& WrongCat)
{
        type = WrongCat.type;
}
WrongCat& WrongCat::operator=(const WrongCat& WrongCat)
{
        type = WrongCat.type;
        return(*this);
}
void WrongCat::makeSound() const
{
        std::cout << "coin coin" << std::endl;
}