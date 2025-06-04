#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;

        bob.promote();
        std::cout << "Promoted: " << bob << std::endl;

        bob.promote();  // Erreur ici : grade va être < 1
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat joe("Joe", 151);  // Erreur ici : grade > 150
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    Bureaucrat joe("Joe", 3);
    Bureaucrat joey("Joey", 6);

    Form papier("papier", 5, 5);
    joe.signForm(papier);
    joe.signForm(papier);
    joey.signForm(papier);
    
    return 0;
}
