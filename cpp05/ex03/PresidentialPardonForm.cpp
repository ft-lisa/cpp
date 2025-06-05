#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm(target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other){}


PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm&)
{
        std::cerr << "Assignment operator is disabled due to const members." << std::endl;
        return *this;
}
PresidentialPardonForm::~PresidentialPardonForm()
{

}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
        if (_signed == false)
            throw NotSigneException() ;
        if (executor.getGrade() > _grade_for_exec)
            throw GradeTooLowException();
        std::cout << _name << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}