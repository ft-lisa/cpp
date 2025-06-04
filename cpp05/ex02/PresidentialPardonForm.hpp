#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
                public :
                        PresidentialPardonForm(std::string name);
                        PresidentialPardonForm(const PresidentialPardonForm&);
                        PresidentialPardonForm& operator=(const PresidentialPardonForm&);
                        ~PresidentialPardonForm();

                        void pardon();


};


#endif