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
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    Cat tigrou;
    const Animal* animal [10];
    tigrou.setIdeas("manger", 1);
    std::cout << tigrou.getIdeas(1) << std::endl;
    Cat tigre(tigrou);
    std::cout << tigre.getIdeas(1) << std::endl;
    for (int i = 0; i < 10; i++)
    {
        if(i < 5)
        {
            animal[i] = new Dog();
        }
        else
        {
            animal[i] = new Cat();
        }
    }
    for (int i = 0; i < 10; i++)
    {
        delete animal[i];
    }

    delete j;
    delete i;
    return 0;
}