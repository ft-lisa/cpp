#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
        public:
                WrongCat();
                ~WrongCat();
                WrongCat(const WrongCat&);
                WrongCat& operator=(const WrongCat&);
                void makeSound() const ;

        private:
};

#endif