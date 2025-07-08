#include "RPN.hpp"


// est ce que chiffre peut etre negatif
// comment on fait pour division par 0
int main(int argc, char** argv)
{
        if (argc != 2)
                return std::cerr << ERR_ARG << std::endl, 1;
        if(check_expression(argv[1]) == 0)
                return 1;
        std::cout << calculated(argv[1]) << std::endl;
        return 0;
}