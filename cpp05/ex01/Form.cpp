#include "Form.hpp"

Form::Form(std::string name, int grade_sign, int grade_exec) :_name(name), _signed(0) , _grade_for_sign(grade_sign), _grade_for_exec(grade_exec)
{
        if (_grade_for_exec < 1 || _grade_for_sign < 1)
                throw GradeTooHighException();
        if (_grade_for_exec > 150 || _grade_for_sign > 150)
                throw GradeTooLowException();
}
Form::Form(const Form& bur): _name(bur._name), _signed(bur._signed),  _grade_for_sign(bur._grade_for_sign),  _grade_for_exec(bur._grade_for_exec)
{

}
Form& Form::operator=(const Form& bur) 
{
        (void)bur;
        std::cerr << "Assignment operator is disabled due to const members." << std::endl;
        return *this;
}


Form::~Form(){}

void Form::beSigned(const Bureaucrat& bur)
{
        if (_signed == true)
                throw AlreadySigneException();
        if (bur.getGrade() > _grade_for_sign)
                throw GradeTooLowException();
        _signed = true;        
        
}

const char* Form::GradeTooHighException::what() const throw()
{
        return "Grade too high!";
}
const char* Form::GradeTooLowException::what() const throw()
{
        return "Grade too low!";
}

const char* Form::AlreadySigneException::what() const throw()
{
        return "the form is already signe";
}

std::string Form::getName ()const
{
        return( _name);
}
bool Form::getSigned ()const
{
        return ( _signed);
}
int Form::getGradeSign ()const
{
        return(_grade_for_sign);
}
int Form::getGradeExec ()const
{
        return(_grade_for_exec);
}

std::ostream& operator<<(std::ostream& os, const Form& b) 
{
        os << "Form '" << b.getName() << "' requires a grade " << b.getGradeSign() << " to be signed and a grade " << b.getGradeExec() << " to be executed. Currently, it is " << (b.getSigned() ? "signed." : "not signed.") << std::endl;

        return os;
}

