#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const std::string name) : WrongAnimal(name)
{
    std::cout << "WrongCat name constructor called" << std::endl;
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat destructor called" << std::endl;
}

std::string     WrongCat::getType(void) const
{
    return (type);
}

void    WrongCat::makeSound(void) const
{
    std::cout << type << " : 야엉" << std::endl;
}