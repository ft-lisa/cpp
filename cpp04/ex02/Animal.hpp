#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>

class Animal
{
        public:

                virtual void makeSound() const;
                std::string getType() const;

        protected:
                std::string type;
                Animal();
                virtual ~Animal();
                Animal(const Animal&);
                Animal& operator=(const Animal&);
        private:
                
};

#endif