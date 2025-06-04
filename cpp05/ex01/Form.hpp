#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>

 #include "Bureaucrat.hpp"

class Form
{
        public :
                Form(std::string name, int grade_sign, int grade_exec);
                Form(const Form&);
                Form& operator=(const Form&);
                ~Form();

                void beSigned(const Bureaucrat&);
                class GradeTooHighException : public std::exception
                {
                        public:
                                const char* what() const throw();
                };
                class GradeTooLowException : public std::exception
                {
                        public:
                                 const char* what() const throw();
                };
                class AlreadySigneException : public std::exception
                {
                        public:
                                const char* what() const throw();
                };

                std::string getName() const;
                bool getSigned() const;
                int getGradeSign() const;
                int getGradeExec() const;
        private :
                const std::string _name;
                bool    _signed;
                const int _grade_for_sign;
                const int _grade_for_exec;

};

std::ostream& operator<<(std::ostream& os, const Form& b);


#endif