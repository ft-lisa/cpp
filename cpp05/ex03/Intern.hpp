#ifndef INTER_HPP
#define INTER_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>

#include "AForm.hpp"

class Intern
{
        public : 
                AForm* makeForm(std::string typeForm, std::string nameForm);
                
                class NotAFormException : public std::exception
                {
                        const char* what() const throw() ;
                };

};

#endif