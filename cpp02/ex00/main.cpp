#include "Fixed.hpp"

void printRedBox(const std::string& text) {
    size_t width = text.length() + 2;

    std::cout << "\033[31m";

    std::cout << "+" << std::string(width, '-') << "+" << std::endl;
    std::cout << "| " << text << " |" << std::endl;
    std::cout << "+" << std::string(width, '-') << "+" << std::endl;

    std::cout << "\033[0m";
}

int main( void ) 
{
        printRedBox("Constructeur");
        Fixed a;
        a.setRawBits(4);
        std::cout << std::endl;
        printRedBox("Constructeur de recopie");
        Fixed b( a );
        std::cout << std::endl;
        printRedBox("Constructeur");
        Fixed c;
        std::cout << std::endl;
        printRedBox("Operateur =");
        c = b;
        std::cout << std::endl; 

        printRedBox("Affectation");
        std::cout << a.getRawBits() << std::endl;
        std::cout << b.getRawBits() << std::endl;
        std::cout << c.getRawBits() << std::endl;
        return 0;
}

// int main( void ) {
// Fixed a;
// Fixed b( a );
// Fixed c;
// c = b;
// std::cout << a.getRawBits() << std::endl;
// std::cout << b.getRawBits() << std::endl;
// std::cout << c.getRawBits() << std::endl;
// return 0;
// }