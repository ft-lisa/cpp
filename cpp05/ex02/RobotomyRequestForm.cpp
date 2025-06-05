#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm(target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other){}


RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm&)
{
        std::cerr << "Assignment operator is disabled due to const members." << std::endl;
        return *this;
}
RobotomyRequestForm::~RobotomyRequestForm()
{

}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
        if (_signed == false)
            throw NotSigneException() ;
        if (executor.getGrade() > _grade_for_exec)
            throw GradeTooLowException();

         std::srand(std::time(0));
        int randomNumber = std::rand() % 100 + 1;
        if (randomNumber % 2 == 0)
                std::cout << _name << " has been robotomized successfully 🤖!" << std::endl;
         else
                std::cout << "Robotomy failed on " << _name << " 💥" << std::endl;
}