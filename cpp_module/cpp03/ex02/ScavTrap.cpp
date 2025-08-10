#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("default")
{
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap name constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &tmp) : ClapTrap()
{
    name = tmp.name;
    hitPoint = tmp.hitPoint;
    energyPoints = tmp.energyPoints;
    attackDamage = tmp.attackDamage;
    std::cout << "ScavTrap copy constructor called" << std::endl;    
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

void    ScavTrap::attack(std::string const &target)
{
    std::cout << "ScavTrap " << name << " attacks " << target << \
        ", causing " << attackDamage << " points of damage! " << std::endl;
}

ScavTrap    &ScavTrap::operator=(const ScavTrap &tmp)
{
    this->name = tmp.name;
    this->hitPoint = tmp.hitPoint;
    this->energyPoints = tmp.energyPoints;
    this->attackDamage = tmp.attackDamage;
    std::cout << "ScavTrap Assignation operator called" << std::endl;
    return (*this);
}

void    ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap have enterred in Gate keeper mode." << std::endl;
}