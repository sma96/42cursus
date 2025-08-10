#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &tmp) : Animal(tmp.type)
{
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::Cat(const std::string name) : Animal(name)
{
    std::cout << "Cat name constructor called" << std::endl;
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &tmp)
{
    Animal::operator=(tmp);
    type = tmp.type;
    std::cout << "Cat Assignation operator called" << std::endl;
    return (*this);
}

std::string     Cat::getType(void) const
{
    return (type);
}

void    Cat::makeSound(void) const
{
    std::cout << type << " : 야옹" << std::endl;
}