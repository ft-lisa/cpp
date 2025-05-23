#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>

class Zombie
{
        public :
                Zombie();
                ~Zombie();
                void announce(void);
                void SetName(std::string name);
                
        private:
                std::string nameZombie_;
};

Zombie* zombieHorde(int N, std::string name);

#endif