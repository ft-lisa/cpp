#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _pv(10), _ep(10), _damage(0)
{
        std::cout << "ClapTrap " << _name << " is create" << std::endl;
}

ClapTrap::~ClapTrap()
{
        std::cout << "ClapTrap " << _name << " is delete" << std::endl;
}

ClapTrap::ClapTrap (const ClapTrap& clap)
{
        _name = clap._name;
        _pv = clap._pv;
        _ep = clap._ep;
        _damage = clap._damage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clap)
{
        _name = clap._name;
        _pv = clap._pv;
        _ep = clap._ep;
        _damage = clap._damage;

        return(*this);
}

void ClapTrap::attack(const std::string& target)
{
        if (_pv <= 0 )
        {
                std::cout << "ClapTrap " << _name << " can't attack because he has no pv" << std::endl;
                return ;
        }        
        if( _ep <= 0)
        {
                std::cout << "ClapTrap " << _name << " can't attack because he has no mana" << std::endl;
                return ;
        }                
        std::cout << "ClapTrap " << _name << " attacks " << target << " , causing " << _damage << " points of damage !" << std::endl;
        _ep--;
                
}

void ClapTrap::takeDamage(unsigned int amount)
{
        if (_pv > 0)
        {
                std::cout << "ClapTrap " << _name << " was hit and lost " << amount << " points of damage !" << std::endl;
                _pv -= amount;
        }        
        else
                std::cout << "ClapTrap " << _name << "is all ready dead" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
        if (_pv <= 0 )
        {
                std::cout << "ClapTrap " << _name << " can't repear itself because he has no pv" << std::endl;
                return ;
        }
        if( _ep <= 0)
        {
                std::cout << "ClapTrap " << _name << " can't repear itself because he has no mana" << std::endl;
                return ;
        }  
        std::cout << "ClapTrap " << _name << " repear itself and win " << amount << " hit point " << std::endl;
        _ep--;
        _pv += amount;     
}
