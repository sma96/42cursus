#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    FragTrap a;
    FragTrap b("smang");
    // ClapTrap a;
    // ClapTrap b("sma");
    // ClapTrap c(b);

    b.takeDamage(5);
    b.takeDamage(2);
    b.beRepaired(5);
    b.attack("ang");
    a = b;
    a.setAd(3);
    a.attack("ang");
    return (0);
}