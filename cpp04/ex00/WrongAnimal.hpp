#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>

class WrongAnimal
{
        public:
                WrongAnimal();
                ~WrongAnimal();
                WrongAnimal(const WrongAnimal&);
                WrongAnimal& operator=(const WrongAnimal&);
                void makeSound() const;
                std::string getType() const;

        protected:
                std::string type;

        private:
};

#endif