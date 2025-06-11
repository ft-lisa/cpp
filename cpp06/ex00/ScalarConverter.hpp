#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>

class ScalarConverter
{
        public :
                static void convert(const std::string&);

        private:
                ScalarConverter();
                ScalarConverter(const ScalarConverter&);
                ScalarConverter& operator=(const ScalarConverter&);
                ~ScalarConverter();


};

#endif