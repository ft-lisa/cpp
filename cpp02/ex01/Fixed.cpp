#include "Fixed.hpp"

Fixed::Fixed () : value_(0) 
{
        std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : value_(value << bit_)
{
        std::cout << "Int constructot called" << std::endl;
}

Fixed::Fixed(const float value) :value_(roundf(value * (1 << bit_)))
{
        std::cout << "Float constructot called" << std::endl;
}

Fixed::Fixed (const Fixed& src)
{
        std::cout << "Copy constructor called" << std::endl;
        value_ = src.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& src)
{
        std::cout << "Copy assignment operator called" << std::endl;
        this->value_ = src.getRawBits();
        return (*this);
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj)
{
        out << obj.toFloat();
        return (out);
}

Fixed::~Fixed () 
{
        std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
        return(value_);
}

void Fixed::setRawBits(int const raw)
{
        std::cout << "setRawbits member function called" << std::endl;
        value_ = raw;
}

float Fixed::toFloat() const
{
        float f;

        f = static_cast<float>(value_) / (1 << bit_);
        return (f);
}

int Fixed::toInt() const
{
        int i;

        i = value_ >> 8;
        return(i);
}

