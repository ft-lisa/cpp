#include "Zombie.hpp"

void printRedBox(const std::string& text) {
    size_t width = text.length() + 2;

    std::cout << "\033[31m";

    std::cout << "+" << std::string(width, '-') << "+" << std::endl;
    std::cout << "| " << text << " |" << std::endl;
    std::cout << "+" << std::string(width, '-') << "+" << std::endl;

    std::cout << "\033[0m";
}

int main(void)
{
        Zombie zomb;
        Zombie *zomb2;
        printRedBox("Zombie Chump");
        randomChump("Foooo");

        printRedBox("New Zombie");
        zomb2 = newZombie("Frites");
        zomb2->announce();

        printRedBox("Annonce with nothing");
        zomb.announce();

        printRedBox("Destruction");
        delete zomb2;

}