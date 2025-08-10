#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class   ClapTrap{
    protected:
        std::string name;
        int hitPoint;
        int energyPoints;
        int attackDamage;
    
    public:
        ClapTrap(void);
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &tmp);
        ~ClapTrap(void);

        ClapTrap    &operator=(const ClapTrap &src);
        void    attack(std::string const &target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        void    setAd(unsigned int amount);
        int     getAd(void);
};

#endif