#ifndef SHRUBERRYCREATIONFORM_HPP
#define SHRUBERRYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>
#include <ctime>

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>
#include <string.h>
       #include <sys/stat.h>
       #include <fcntl.h>
       #include <fstream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
                public :
                        ShrubberyCreationForm(std::string name);
                        ShrubberyCreationForm(const ShrubberyCreationForm&);
                        ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);
                        ~ShrubberyCreationForm();

                        void execute(Bureaucrat const& executor) const;


};


#endif