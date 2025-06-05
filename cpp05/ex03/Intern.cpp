#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

AForm* Intern::makeForm(std::string typeForm, std::string nameForm)
{
        char lettre = typeForm[0];

        if (strcmp(typeForm.c_str(), "robotomy request") && strcmp(typeForm.c_str(), "presidential pardon") && strcmp(typeForm.c_str(), "shruberry creation"))
                throw NotAFormException();
        std::cout << "Intern creates " << typeForm << std::endl;
        switch (lettre)
        {
                case 'r':        
                        return new RobotomyRequestForm (nameForm);
                case 'p':
                        return new PresidentialPardonForm (nameForm);
                default:
                        return new ShrubberyCreationForm (nameForm);
        }
}
                
const char* Intern::NotAFormException::what() const throw()
{
        return "The provided form name does not exist";
}