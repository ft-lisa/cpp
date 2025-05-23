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
        int nbr = 4;
        Zombie zomb;
        Zombie *zomb2;
        Zombie *start;

        printRedBox("horde Zombie");
        zomb2 = zombieHorde(nbr, "Frites");
        start = zomb2;
        while (nbr - 1 >= 0)
        {
            zomb2->announce();
            zomb2++;
            nbr--;
        }
        printRedBox("Annonce with nothing");
        zomb.announce();

        printRedBox("Destruction");
        delete[] start;

}