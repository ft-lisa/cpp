#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>
#include "Animal.hpp"

class Dog : public Animal
{
        public:
                Dog();
                ~Dog();
                Dog(const Dog&);
                Dog& operator=(const Dog&);
                void makeSound() const;

        private:
};

#endif