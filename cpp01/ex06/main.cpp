#include "Harl.hpp"

void printRedBox(const std::string& text) {
    size_t width = text.length() + 2;

    std::cout << "\033[31m";

    std::cout << "+" << std::string(width, '-') << "+" << std::endl;
    std::cout << "| " << text << " |" << std::endl;
    std::cout << "+" << std::string(width, '-') << "+" << std::endl;

    std::cout << "\033[0m";
}

int main(int argc, char** argv)
{
        Harl harl;
        if (argc != 2)
            return std::cerr << "./harlFilter [level]" << std::endl, 1;
        harl.complain(argv[1]);
}