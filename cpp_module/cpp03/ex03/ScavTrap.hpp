#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class   ScavTrap : public virtual ClapTrap{
    public:
        ScavTrap(void);
        ScavTrap(const std::string name);
        ScavTrap(const ScavTrap &tmp);
        ~ScavTrap(void);

        ScavTrap    &operator=(const ScavTrap &tmp);

        void        attack(std::string const &target);
        void        guardGate(void);
};
#endif