#include "BitcoinExchange.hpp"

int main (int argc, char** argv)
{
    if (argc != 2)
        return std::cerr << ERR_NO_FILE << std::endl, 1;
    if (calcule_bitcoin(argv[1]) == 0)
        return(1);
    return 0;
}