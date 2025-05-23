#include "Harl.hpp"

void printRedBox(const std::string& text) {
    size_t width = text.length() + 2;

    std::cout << "\033[31m";

    std::cout << "+" << std::string(width, '-') << "+" << std::endl;
    std::cout << "| " << text << " |" << std::endl;
    std::cout << "+" << std::string(width, '-') << "+" << std::endl;

    std::cout << "\033[0m";
}

int main(void)
{
        Harl harl;
        printRedBox("Wrong level");
        harl.complain("COUCOU");

        printRedBox("level debug");
        harl.complain("DEBUG");

        printRedBox("level info");
        harl.complain("INFO");

        printRedBox("level warning");
        harl.complain("WARNING");
        
        printRedBox("level error");
        harl.complain("ERROR");
}