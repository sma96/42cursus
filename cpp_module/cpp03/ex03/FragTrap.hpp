#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class   FragTrap : public virtual ClapTrap{
    public:
        FragTrap(void);
        FragTrap(const std::string name);
        FragTrap(const FragTrap &tmp);
        ~FragTrap(void);

        FragTrap    &operator=(const FragTrap &tmp);

        void        attack(std::string const &target);
        void        highFivesGuys(void);
};
#endif