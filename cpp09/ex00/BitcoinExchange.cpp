#include "BitcoinExchange.hpp"


int check_date(std::string line)
{

}
int check_value(std::string line, int size)
{
    line.erase(0, size);
    int value;
    std::stringstream num(line);
    if (num >> value)
    {
        if (value >= 0 && value <= 1000)
            return 1;
        else 
            return 0;
    }
    else
        return 1;

}

int check_line(std::ifstream file)
{
    std::string line;
    while(std::getline(file, line))
    {
        size_t first = line.find(" | ");
        size_t second = line.find(" | ", first + 1);

        if (first != std::string::npos && second == std::string::npos)
        {
            if (check_date(line) == 0)
                return 1;
            if (check_value(line, second) == 0)
                return 1;
        }
        else
            return std::cerr << ERR_LINE << std::endl, 0;
        }
}

int check_file(std::string str)
{
    std::ifstream data("data.csv");
    if (!data)
        return std::cerr << ERR_FILE << std::endl, 0;
    std::ifstream file(str);
    if (!file)
        return std::cerr << ERR_FILE << std::endl, 0;
    check_line(file);
}