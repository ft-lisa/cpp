#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>
#include <ctime>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
                public :
                        RobotomyRequestForm(std::string name);
                        RobotomyRequestForm(const RobotomyRequestForm&);
                        RobotomyRequestForm& operator=(const RobotomyRequestForm&);
                        ~RobotomyRequestForm();

                        void execute(Bureaucrat const& executor) const;


};


#endif