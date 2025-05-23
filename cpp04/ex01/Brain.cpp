#include "Brain.hpp"

Brain::Brain()
{
        std::cout << "Construction de Brain" << std::endl;
}
Brain::~Brain()
{
        std::cout << "Destruction de Brain" << std::endl;
}
Brain::Brain(const Brain& brain)
{
    for (int i = 0; i < 100; ++i)
        ideas[i] = brain.ideas[i];
}

Brain& Brain::operator=(const Brain& brain) 
{
    if (this != &brain) {
        for (int i = 0; i < 100; ++i)
            ideas[i] = brain.ideas[i];
    }
    return *this;
}

void Brain::setIdeas(std::string str, int i)
{
    if (i < 0 || i > 99)
        return ;
    ideas[i] = str;
}
std::string Brain::getIdeas(int i)
{
    if (i < 0 || i > 99)
        return (NULL) ;
    return (ideas[i]);
}
