#include "RPN.hpp"

int main(int argc, char** argv)
{
        try
        {
                if (argc != 2)
                        return std::cerr << ERR_ARG << std::endl, 1;
                if(check_expression(argv[1]) == 0)
                        return 1;
                std::cout << calculated(argv[1]) << std::endl;
                return 0;
        } 
        catch (const std::runtime_error& e) 
        {
                std::cerr << "Error: " << e.what() << std::endl;
        }
}