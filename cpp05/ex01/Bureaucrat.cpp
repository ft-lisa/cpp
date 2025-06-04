#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->_grade = grade;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const 
{
    return _name;
}

int Bureaucrat::getGrade() const 
{
    return _grade;
}

void Bureaucrat::promote() 
{
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::demote() 
{
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    _grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
    return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
    return "Grade too low!";
}

void Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;  
    }
    catch (std::exception& exep)
    {
        std::cout << _name <<  " couldn’t sign " << form.getName() << " because "  << exep.what() << "." << std::endl;
    }
      
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) 
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}
