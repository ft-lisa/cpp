#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>

// #include "Form.hpp"
class AForm;

class Bureaucrat
{
        public :
                Bureaucrat(std::string const &name, int grade);
                Bureaucrat(const Bureaucrat&);
                Bureaucrat& operator=(const Bureaucrat&);
                ~Bureaucrat();

                std::string getName() const;
                int getGrade() const;
                void demote();
                void promote();
                void signForm(AForm&);
                void execution(AForm&);

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
                class NotSigneException : public std::exception
                {
                        public:
                                const char* what() const throw();
                };
                void GradeUp();
                void GradeDown();

        private :
                const std::string _name;
                int _grade;


};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);


#endif