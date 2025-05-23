#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>

int main(void)
{
        std::string stringORI = "HI  THIS IS BRAIN";
        std::string *stringPTR = &stringORI;
        std::string &stringREF = stringORI;

        std::cout << "Adresse de memoire de la string : " << &stringORI << std::endl ;
        std::cout << "Adresse memoire du pointer : " << stringPTR << std::endl;
        std::cout << "Adresse memoire de la reference : " << &stringREF << std::endl;

        std::cout << "La valeur de la string : " << stringORI << std::endl;
        std::cout << "La valeur du pointer : " << *stringPTR << std::endl;
        std::cout << "La valeur de la reference : " << stringREF << std::endl;

        return(0);
}