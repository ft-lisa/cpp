#include "BitcoinExchange.hpp"

int check_date(std::string line)
{
    std::string date = line;
    int year;
    int month;
    int day;

    if ( line.size() > 10 && !(line[4] == '-' && line[7] == '-'))
        return std::cerr << ERR_DATE << line << std::endl, 0;
    year = atoi(line.c_str());
    line.erase(0, 5);
    month = atoi(line.c_str());
    line.erase(0, 3);
    day = atoi(line.c_str());

    std::tm timeinfo = {};
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_mday = day;

    std::mktime(&timeinfo);
    if (timeinfo.tm_year == year - 1900 &&
            timeinfo.tm_mon  == month - 1 &&
            timeinfo.tm_mday == day)
        return 1;
    std::cerr << ERR_DATE  << date << std::endl;
    return (0);
}
int check_value(std::string line)
{

    size_t size = line.find(" | ");
    size += 2;
    line.erase(0, size);
    float value;
    std::stringstream num(line);
    if (num >> value)
    {
        if (value < 0)
            return std::cerr << ERR_NVAL << std::endl, 0;
        if (value > 1000)
            return std::cerr << ERR_VAL << std::endl, 0;
        return  1;            
    }
    else
        return std::cerr << ERR_CHAR << line << std::endl, 0;

}

int check_line(std::string line)
{
    size_t first = line.find(" | ");
    size_t second = line.find(" | ", first + 1);

    if (first != std::string::npos && second == std::string::npos)
        return 1;
    else
        return std::cerr << ERR_LINE  << line << std::endl, 0;
    return 1;
}

int check_files(std::string str, std::ifstream& data, std::ifstream& file)
{
    data.open("data.csv");
    if (!data)
        return std::cerr << ERR_FILE << std::endl, 0;
    file.open(str.c_str());
    if (!file)
        return std::cerr << ERR_FILE << std::endl, 0;
    return 1;
}

std::map<std::string, float> fill_data(std::ifstream& data)
{
    std::string line;
    std::string copy;
    std::map<std::string, float> map;

    while(std::getline(data, line))
    {
        copy = line;
        size_t size = line.find(",");
        line.erase(size, line.size());
        size++;
        copy.erase(0, size);
        map[line] = atof(copy.c_str());
    }
    return map;
}

void calcule(std::map<std::string, float> data, std::string line)
{
    float price;
    float number;
    std::string copy = line;

    int year;
    int month;
    int day;
    char delim1, delim2;

    size_t size = line.find(" | ");
    line.erase(size, line.size());
    size += 3;
    copy.erase(0, size);
    std::string old_date = line;
    while (1)
    {   
        //std::cout << line << std::endl;
        
        if (data.find(line) != data.end())
        {
            price = data[line];
            number = atof(copy.c_str());
            std::cout << old_date << " => " << number << " => " << number * price << std::endl ;
            return ;
        }

        std::istringstream toint(line);
        toint >> year >> delim1 >> month >> delim2 >> day;
        if (year < 2009 || year > 2022)
        {
            std::cout << "error date" << std::endl ;
            return ;
        }
        //std::cout << "date: " << year << "-" << month << "-" << day << std::endl;
        day--;
        std::tm timeinfo = {};
        timeinfo.tm_year = year - 1900;
        timeinfo.tm_mon = month - 1;
        timeinfo.tm_mday = day;

        std::mktime(&timeinfo);

        year  = timeinfo.tm_year + 1900;
        month = timeinfo.tm_mon + 1;
        day   = timeinfo.tm_mday;

        std::ostringstream tostring;
        tostring << year << "-" << std::setfill('0') << std::setw(2) << month << "-"
        << std::setfill('0') << std::setw(2) << day;

        line = tostring.str();
    }
}

int calcule_bitcoin(std::string str)
{
    std::ifstream data;
    std::ifstream file;
    std::string line;
    std::map<std::string, float> map;

    check_files(str, data, file);
    map = fill_data(data);
    while(std::getline(file, line))
    {
        //std::cout << line << std::endl;

        if (strcmp(line.c_str(), "date | value")&& check_date(line) && check_line(line)   && check_value(line))
        {
            calcule(map, line);
        }

    }
    return 1;
}