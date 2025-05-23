#include "ClapTrap.hpp"

void printRedBox(const std::string& text) {
    size_t width = text.length() + 2;

    std::cout << "\033[31m";

    std::cout << "+" << std::string(width, '-') << "+" << std::endl;
    std::cout << "| " << text << " |" << std::endl;
    std::cout << "+" << std::string(width, '-') << "+" << std::endl;

    std::cout << "\033[0m";
}

int main()
{
        printRedBox("Create class");
        ClapTrap frites("Frites");
        ClapTrap burger("Burger");

        printRedBox("Attack");
        frites.attack("Tortue");

        printRedBox("Repear");
        frites.beRepaired(1);
        printRedBox("with no life");
        frites.takeDamage(11);
        frites.attack("Tortue");
        frites.beRepaired(1);


        printRedBox("with no mana");
        burger.attack("Tortue");
        burger.attack("Tortue");
        burger.attack("Tortue");
        burger.attack("Tortue");
        burger.attack("Tortue");
        burger.attack("Tortue");
        burger.attack("Tortue");
        burger.attack("Tortue");
        burger.attack("Tortue");
        burger.attack("Tortue");
        
        burger.attack("Tortue");
        burger.beRepaired(1);
}