#include "Fixed.hpp"

#include <stdio.h>

void printRedBox(const std::string& text) {
    size_t width = text.length() + 2;

    std::cout << "\033[31m";

    std::cout << "+" << std::string(width, '-') << "+" << std::endl;
    std::cout << "| " << text << " |" << std::endl;
    std::cout << "+" << std::string(width, '-') << "+" << std::endl;

    std::cout << "\033[0m";
}

// int main( void ) {
// Fixed a;
// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// std::cout << a << std::endl;
// std::cout << ++a << std::endl;
// std::cout << a << std::endl;
// std::cout << a++ << std::endl;
// std::cout << a << std::endl;
// std::cout << b << std::endl;
// std::cout << Fixed::max( a, b ) << std::endl;
// return 0;
// }

int main( void ) 
{
    Fixed a(15);
    Fixed b(3.5f);

    printRedBox("Comparaison");

    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "a < b : " << (a < b) << std::endl;
    std::cout << "a > b : " << (a > b) << std::endl;
    std::cout << "a <= b : " << (a <= b) << std::endl;
    std::cout << "a >= b : " << (a >= b) << std::endl;
    std::cout << "a == b : " << (a == b) << std::endl;
    std::cout << "a != b : " << (a != b) << std::endl;

    printRedBox("Operation");

    std::cout << "a + b = " << (a + b) << std::endl;
    std::cout << "a - b = " << (a - b) << std::endl;
    std::cout << "a * b = " << (a * b) << std::endl;
    std::cout << "a / b = " << (a / b) << std::endl;

    printRedBox("Incrementation, Decrementation");

    Fixed c = a;
    std::cout << "c = " << c << std::endl;

    std::cout << "++c = " << ++c << std::endl;
    std::cout << "c++ = " << c++ << std::endl;
    std::cout << "After c++ : " << c << std::endl;

    std::cout << "--c = " << --c << std::endl;
    std::cout << "c-- = " << c-- << std::endl;
    std::cout << "After c-- : " << c << std::endl;

    printRedBox("max | min");

    std::cout << "a = " << a.max(a, b) << std::endl;
    std::cout << "b = " << a.min(a, b) << std::endl;
    
    return 0;
}

