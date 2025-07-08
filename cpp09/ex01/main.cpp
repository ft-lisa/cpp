#include "RPN.hpp"

int main(int argc, char** argv)
{
        if (argc != 2)
                return std::cout << "error" << std::endl, 1;
        if(check_expression(argv[1]) == 0)
                return 1;
        std::cout << "resultat : " << calculated(argv[1]) << std::endl;
        // fill_stack(argv[1]);
        return 0;
}