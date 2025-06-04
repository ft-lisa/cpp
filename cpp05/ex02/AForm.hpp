#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>

#include "Bureaucrat.hpp"

class AForm
{
        public :

                ~AForm();

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
        protected :
                AForm(std::string name, int grade_sign, int grade_exec);
                AForm(const AForm&);
                AForm& operator=(const AForm&);
                const std::string _name;
                bool    _signed;
                const int _grade_for_sign;
                const int _grade_for_exec;

};

std::ostream& operator<<(std::ostream& os, const AForm& b);


#endif