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
                void set_name(std::string name);

        private:
                std::string nameZombie;
};
        Zombie* newZombie(std::string name);
        void randomChump(std::string name);
#endif