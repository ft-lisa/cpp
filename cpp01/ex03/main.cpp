#include "HumanA.hpp"
void printRedBox(const std::string& text)
 {
    size_t width = text.length() + 2;

    std::cout << "\033[31m";

    std::cout << "+" << std::string(width, '-') << "+" << std::endl;
    std::cout << "| " << text << " |" << std::endl;
    std::cout << "+" << std::string(width, '-') << "+" << std::endl;

    std::cout << "\033[0m";
}

int main()
{
        {
                printRedBox("Human A");
                Weapon club = Weapon("crude spiked club");
                HumanA bob("Bob", club);
                bob.attack();
                club.setType("some other type of club");
                bob.attack();
        }
        {
                printRedBox("Human B sans arme");
                Weapon club = Weapon("crude spiked club");
                HumanB jim("Jim");
                jim.attack();
                printRedBox("Human B avec arme");
                jim.setWeapon(club);
                jim.attack();
                club.setType("some other type of club");
                jim.attack();
        }
        return 0;
}