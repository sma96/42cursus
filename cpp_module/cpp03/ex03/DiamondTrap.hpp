#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap{
    private:
        std::string name;

    public:
        DiamondTrap(void);
        DiamondTrap(const std::string name);
        DiamondTrap(const DiamondTrap &tmp);
        ~DiamondTrap(void);
    
        DiamondTrap    &operator=(const DiamondTrap &tmp);

        void        attack(std::string const &target);
        void        whoAmI(void);
};
#endif