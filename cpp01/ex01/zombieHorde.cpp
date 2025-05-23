#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name )
{

        Zombie *zombie = new Zombie[N];
        Zombie *start = zombie;
        while (N - 1 >= 0)
        {
                zombie->SetName(name);
                zombie++;
                N--;
        }
        return(start);
        
}