#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
        public:
                Cat();
                ~Cat();
                Cat(const Cat&);
                Cat& operator=(const Cat&);
                void makeSound() const ;
                void setIdeas(std::string str, int i);
                std::string getIdeas(int i);
        private:
                Brain* _brain;
};

#endif