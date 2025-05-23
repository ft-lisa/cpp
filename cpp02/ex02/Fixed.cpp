#include "Fixed.hpp"

Fixed::Fixed () : value_(0) 
{
        // std::cout << "\033[35m" << "Default constructor called" << "\033[0m" << std::endl;
}

Fixed::Fixed(const int value) : value_(value << bit_)
{
        // std::cout << "\033[35m" << "Int constructot called" << "\033[0m" << std::endl;
}

Fixed::Fixed(const float value) :value_(roundf(value * (1 << bit_)))
{
        // std::cout << "\033[35m" << "Float constructot called" << "\033[0m" << std::endl;
}

Fixed::Fixed (const Fixed& src)
{
        // std::cout << "\033[35m" << "Copy constructor called" << "\033[0m" << std::endl;
        value_ = src.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& src)
{
        // std::cout << "\033[35m" << "Copy assignment operator called" << "\033[0m" << std::endl;
        this->value_ = src.getRawBits();
        return (*this);
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj)
{
        out << obj.toFloat();
        return (out);
}
bool Fixed::operator<(const Fixed& b)
{
        if (this->value_ < b.value_)
                return(1);
        return(0);
}

bool Fixed::operator>(const Fixed& b)
{
        if (this->value_ > b.value_)
                return(1);
        return(0);
}

bool Fixed::operator>=(const Fixed& b)
{
        if (this->value_ >= b.value_)
                return(1);
        return(0);
}
bool Fixed::operator<=(const Fixed& b)
{
        if (this->value_ <= b.value_)
                return(1);
        return(0);
}
bool Fixed::operator==(const Fixed& b)
{
        if (this->value_ == b.value_)
                return(1);
        return(0);
}

bool Fixed::operator!=(const Fixed& b)
{
        if (this->value_ != b.value_)
                return(1);
        return(0);
}

Fixed Fixed::operator+(const Fixed& b)
{
        Fixed result;
        result.setRawBits(this->value_ + b.getRawBits());
        return(result);
}

Fixed Fixed::operator-(const Fixed& b)
{
        Fixed result;
        result.setRawBits(this->value_ - b.getRawBits());
        return(result);
}

Fixed Fixed::operator*(const Fixed& b)
{
        Fixed result;
        result.setRawBits((this->value_ * b.getRawBits()) >> bit_);
        return(result);
}

Fixed Fixed::operator/(const Fixed& b)
{
        Fixed result;
        result.setRawBits((this->value_ / b.getRawBits()) << bit_);
        return(result);
}

Fixed Fixed::operator++()
{
        value_++;
        return(*this);
}

Fixed Fixed::operator++(int)
{
        Fixed tmp = *this;
        value_++;
        return(tmp);
}

Fixed Fixed::operator--(int)
{
        Fixed tmp = *this;
        value_--;
        return(tmp);
}

Fixed Fixed::operator--()
{
        value_++;
        return(*this);
}

Fixed::~Fixed () 
{
        // std::cout << "\033[35m" << "Destructor called" << "\033[0m" << std::endl;
}

int Fixed::getRawBits() const
{
        return(value_);
}

void Fixed::setRawBits(int const raw)
{
        // std::cout << "\033[35m" << "setRawbits member function called" << "\033[0m" << std::endl;
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

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
        if (a.getRawBits() < b.getRawBits()) 
                return(a);
        return(b);
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
        if (a.getRawBits() < b.getRawBits()) 
                return(a);
        return(b);
}
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
        if (a.getRawBits() > b.getRawBits()) 
                return(a);
        return(b);
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
        if (a.getRawBits() > b.getRawBits()) 
                return(a);
        return(b);
}

