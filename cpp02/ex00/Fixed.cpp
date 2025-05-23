#include "Fixed.hpp"

Fixed::Fixed () : value(0) 
{
        std::cout << "\033[35m" << "Default constructor called" << "\033[0m" << std::endl;
}

Fixed::Fixed (const Fixed& src)
{
        std::cout << "\033[35m" << "Copy constructor called" << "\033[0m" << std::endl;
        value = src.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& src)
{
        std::cout << "\033[35m" << "Copy assignment operator called" << "\033[0m" << std::endl;
        this->value = src.getRawBits();
        return (*this);
}

Fixed::~Fixed () 
{
        std::cout << "\033[35m" << "Destructor called" << "\033[0m" << std::endl;
}

int Fixed::getRawBits() const
{
        std::cout << "\033[35m" << "getRawBits member function called" << "\033[0m" << std::endl;
        return(value);
}

void Fixed::setRawBits(int const raw)
{
        std::cout << "\033[35m" << "setRawbits member function called" << "\033[0m" << std::endl;
        value = raw;
}