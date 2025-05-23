#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
         _pv = 100;
         _ep = 100;
         _damage = 30;
        std::cout << "FrapTrap " << _name << " is create" << std::endl;
}

FragTrap::~FragTrap()
{

}

FragTrap::FragTrap (const FragTrap& clap) : ClapTrap(clap._name)
{
        _name = clap._name;
        _pv = clap._pv;
        _ep = clap._ep;
        _damage = clap._damage;
        std::cout << "FragTrap " << _name << " is create with recopie" << std::endl;

}

FragTrap& FragTrap::operator=(const FragTrap& clap) //: ClapTrap(clap._name)
{
        _name = clap._name;
        _pv = clap._pv;
        _ep = clap._ep;
        _damage = clap._damage;

        std::cout << "FragTrap " << _name << " is create with operator =" << std::endl;


        return(*this);
}

void FragTrap::highFivesGuys()
{
        std::cout << "FrapTrap " << _name << " want a high-fives" << std::endl;
}