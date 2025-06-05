#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {
    // try {
    //     Bureaucrat bob("Bob", 2);
    //     std::cout << bob << std::endl;

    //     bob.promote();
    //     std::cout << "Promoted: " << bob << std::endl;

    //     bob.promote();  // Erreur ici : grade va être < 1
    // }
    // catch (std::exception &e) {
    //     std::cerr << "Exception caught: " << e.what() << std::endl;
    // }

    // try {
    //     Bureaucrat joe("Joe", 151);  // Erreur ici : grade > 150
    // }
    // catch (std::exception &e) {
    //     std::cerr << "Exception caught: " << e.what() << std::endl;
    // }


    // try{
    //     Bureaucrat joe("Joe", 3);
    //     PresidentialPardonForm presi("presi");
    //     presi.execute(joe);
    // }
    // catch (std::exception &exep)
    // {
    //     std::cerr << "Error : " << exep.what() << std::endl;
    // }
    // try{
    //     Bureaucrat joe("Joe", 3);
    //     PresidentialPardonForm presi("presi");
    //     joe.signForm(presi);
    //     presi.execute(joe);
    // }
    // catch (std::exception &exep)
    // {
    //     std::cerr << "Error : " << exep.what() << std::endl;
    // }



    // try{
    //     Bureaucrat joe("Joe", 3);
    //     RobotomyRequestForm presi("presi");
    //     presi.execute(joe);
    // }
    // catch (std::exception &exep)
    // {
    //     std::cerr << "Error : " << exep.what() << std::endl;
    // }
    // try{
    //     Bureaucrat joe("Joe", 3);
    //     RobotomyRequestForm  presi("presi");
    //     joe.signForm(presi);
    //     presi.execute(joe);
    // }
    // catch (std::exception &exep)
    // {
    //     std::cerr << "Error : " << exep.what() << std::endl;
    // }





    // try{
    //     Bureaucrat joe("Joe", 3);
    //     ShrubberyCreationForm presi("presi");
    //     presi.execute(joe);
    // }
    // catch (std::exception &exep)
    // {
    //     std::cerr << "Error : " << exep.what() << std::endl;
    // }
    // try{
    //     Bureaucrat joe("Joe", 3);
    //     ShrubberyCreationForm  presi("presi");
    //     joe.signForm(presi);
    //     presi.execute(joe);
    // }
    // catch (std::exception &exep)
    // {
    //     std::cerr << "Error : " << exep.what() << std::endl;
    // }

    try {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    }
    catch (std::exception &exep)
    {
        std::cerr << "Error :" << exep.what() << std::endl;
    }

        try {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robo request", "Bender");
    }
    catch (std::exception &exep)
    {
        std::cerr << "Error :" << exep.what() << std::endl;
    }
    
    
    
    return 0;
}
