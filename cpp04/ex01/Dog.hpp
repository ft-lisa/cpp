#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
        public:
                Dog();
                ~Dog();
                Dog(const Dog&);
                Dog& operator=(const Dog&);
                void makeSound() const;
                void setIdeas(std::string str, int i);
                std::string getIdeas(int i);

        private:
                Brain* _brain;
};

#endif