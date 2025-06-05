#include "AForm.hpp"

AForm::AForm(std::string name, int grade_sign, int grade_exec) :_name(name), _signed(0) , _grade_for_sign(grade_sign), _grade_for_exec(grade_exec)
{
        if (_grade_for_exec < 1 || _grade_for_sign < 1)
                throw GradeTooHighException();
        if (_grade_for_exec > 150 || _grade_for_sign > 150)
                throw GradeTooLowException();
}
AForm::AForm(const AForm& bur): _name(bur._name), _signed(bur._signed),  _grade_for_sign(bur._grade_for_sign),  _grade_for_exec(bur._grade_for_exec)
{

}
AForm& AForm::operator=(const AForm& bur) 
{
        (void)bur;
        std::cerr << "Assignment operator is disabled due to const members." << std::endl;
        return *this;
}


AForm::~AForm(){}

void AForm::beSigned(const Bureaucrat& bur)
{
        if (_signed == true)
                throw AlreadySigneException();
        if (bur.getGrade() > _grade_for_sign)
                throw GradeTooLowException();
        _signed = true;        
        
}

const char* AForm::GradeTooHighException::what() const throw()
{
        return "Grade too high!";
}
const char* AForm::GradeTooLowException::what() const throw()
{
        return "Grade too low!";
}

const char* AForm::AlreadySigneException::what() const throw()
{
        return "the Aform is already signe";
}

const char* AForm::NotSigneException::what() const throw()
{
        return "the Aform is not signe";
}

const char* AForm::NotCreatFile::what() const throw()
{
        return "Echec de la creation du fichier";
}

std::string AForm::getName ()const
{
        return( _name);
}
bool AForm::getSigned ()const
{
        return ( _signed);
}
int AForm::getGradeSign ()const
{
        return(_grade_for_sign);
}
int AForm::getGradeExec ()const
{
        return(_grade_for_exec);
}

std::ostream& operator<<(std::ostream& os, const AForm& b) 
{
        os << "AForm '" << b.getName() << "' requires a grade " << b.getGradeSign() << " to be signed and a grade " << b.getGradeExec() << " to be executed. Currently, it is " << (b.getSigned() ? "signed." : "not signed.") << std::endl;

        return os;
}

void AForm::execute(Bureaucrat const & executor) const
{
        (void)executor;
}


