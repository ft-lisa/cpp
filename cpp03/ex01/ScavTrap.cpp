#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
         _pv = 100;
         _ep = 50;
         _damage = 20;
        std::cout << "ScavTrap " << _name << " is create" << std::endl;
}

ScavTrap::~ScavTrap()
{
        std::cout << "ScavTrap " << _name << " is delete" << std::endl;
}

ScavTrap::ScavTrap (const ScavTrap& clap) : ClapTrap(clap._name)
{
        _name = clap._name;
        _pv = clap._pv;
        _ep = clap._ep;
        _damage = clap._damage;
        std::cout << "ScavTrap " << _name << " is create with recopie" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& clap)
{
        _name = clap._name;
        _pv = clap._pv;
        _ep = clap._ep;
        _damage = clap._damage;
        std::cout << "ScavTrap " << _name << " is create with operator =" << std::endl;

        return(*this);
}

void ScavTrap::attack(const std::string& target)
{
        if (_pv <= 0 )
        {
                std::cout << "ScavTrap " << _name << " can't attack because he has no pv" << std::endl;
                return ;
        }        
        if( _ep <= 0)
        {
                std::cout << "ScavTrap " << _name << " can't attack because he has no mana" << std::endl;
                return ;
        }                
        std::cout << "ScavTrap " << _name << " attacks " << target << " , causing " << _damage << " points of damage !" << std::endl;
        _ep--;
}

void ScavTrap::guardGate()
{
        std::cout << "ScavTrap " << _name << " is now in Gatekeeper mode" << std::endl;
}

