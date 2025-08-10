#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("default")
{
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap name constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &tmp) : ClapTrap()
{
    name = tmp.name;
    hitPoint = tmp.hitPoint;
    energyPoints = tmp.energyPoints;
    attackDamage = tmp.attackDamage;
    std::cout << "FragTrap copy constructor called" << std::endl;    n
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap destructor called" << std::endl;
}

void    FragTrap::attack(std::string const &target)
{
    std::cout << "FragTrap " << name << " attacks " << target << \
        ", causing " << attackDamage << " points of damage! " << std::endl;
}

FragTrap    &FragTrap::operator=(const FragTrap &tmp)
{
    this->name = tmp.name;
    this->hitPoint = tmp.hitPoint;
    this->energyPoints = tmp.energyPoints;
    this->attackDamage = tmp.attackDamage;
    std::cout << "FragTrap Assignation operator called" << std::endl;
    return (*this);
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "high5!?" << std::endl;
}