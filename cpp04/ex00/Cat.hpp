#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>
#include "Animal.hpp"

class Cat : public Animal
{
        public:
                Cat();
                ~Cat();
                Cat(const Cat&);
                Cat& operator=(const Cat&);
                void makeSound() const ;

        private:
};

#endif