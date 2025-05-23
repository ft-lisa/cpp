#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

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
        FragTrap frites("Frites");
        FragTrap Burger(frites);
        FragTrap Salade("salade");
        Salade = Burger;
        printRedBox("Test de l'heritage");
        frites.attack("Burger");
        frites.takeDamage(99);
        frites.beRepaired(1);
        printRedBox("Sans vie");
        frites.takeDamage(2);
        frites.attack("Burger");
        frites.takeDamage(99);
        frites.beRepaired(1);
        frites.highFivesGuys();


}