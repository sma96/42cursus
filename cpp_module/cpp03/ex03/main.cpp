#include "DiamondTrap.hpp"

int main(void)
{
    // DiamondTrap dia;
    std::cout << "-----------------------------------" << std::endl;

    DiamondTrap dia3;

    std::cout << "-----------------------------------" << std::endl;
    
    DiamondTrap dia2("sma");
    
    std::cout << "-----------------------------------" << std::endl;

    dia3 = dia2;

    std::cout << "-----------------------------------" << std::endl;
    // dia.whoAmI();
    
    dia2.whoAmI();
    dia3.whoAmI();

    std::cout << "-----------------------------------" << std::endl;
    // dia2.attack("ang");
    return (0);
}