#include "Span.hpp"


int main()
{
    Span sp = Span(8);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    sp.addNumbers(2, 3);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span span;
        std::cout << span.shortestSpan() << std::endl;

}
