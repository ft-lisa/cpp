#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

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
        printRedBox("Construction classe avec heritage");
        Cat tigrou;
        tigrou.setIdeas("manger", 1);
        std::cout << tigrou.getIdeas(1) << std::endl;
        Cat tigre(tigrou);
        Cat tig;
        tig = tigre;
        std::cout << tigre.getIdeas(1) << std::endl;
        std::cout << tig.getIdeas(1) << std::endl;
        printRedBox("Type des animaux");
        std::cout << tig.getType() << " " << std::endl;

        printRedBox("Son des animaux");
        tigre.makeSound();


        printRedBox("Wrong animal");
        WrongAnimal animal;
        WrongCat canard;
        const WrongAnimal* k = new WrongCat();

        std::cout << animal.getType() << " " << std::endl;
        std::cout << canard.getType() << " " << std::endl;
        std::cout << k->getType() << " " << std::endl << std::endl;

        animal.makeSound();
        canard.makeSound();
        k->makeSound();
        printRedBox("Destruction des classes");
        delete k;
        return 0;
}