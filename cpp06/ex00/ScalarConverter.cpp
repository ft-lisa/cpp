#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& litteral)
{
        char    c;
        int     i;
        float   f;
        double  d;
        char* end;

        f = std::strtof(litteral.c_str(), &end);
        d = std::strtod(litteral.c_str(), NULL);
        i = static_cast<int>(d);
        c = i;

        if (!((*end == 'f' && *(end + 1) == '\0') || (*end == '\0')))
                return;
        // char
        if (i < 0 || i > 127)
                std::cout << "char: " << "impossible" << std::endl;
        else if (i == 127 || i < 32)
                std::cout << "char: " << "Non displayable" << std::endl;
        else
                std::cout << "char: " << c << std::endl;

        // int
        if (d < -2147483648 || d > 2147483647 || litteral == "nan" ||  litteral == "nanf")
                std::cout << "int: " << "impossible" << std::endl;
        else
                std::cout << "int: " << i << std::endl;

        // float and double
        if (litteral == "+inf" || litteral == "inf" )
        {
                std::cout << "float: " << "+" << std::fixed << std::setprecision(1) << f << "f" << std::endl;
                std::cout << "double: " << "+" << d << std::endl;
        }        
        else
        {
                std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
                std::cout << "double: " << d << std::endl;
        }
        
}

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter&)
{

}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&)
{
        return *this;
}

ScalarConverter::~ScalarConverter()
{

}
