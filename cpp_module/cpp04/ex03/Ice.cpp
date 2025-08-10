#include "Ice.hpp"

Ice::Ice(void) : AMteria("ice")
{
    std::cout <<  "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &tmp) : AMteria(tmp.type)
{
    std::cout << "Ice copy constructor called" << std::endl;
}

Ice::Ice(std::string const &type) : AMteria(type)
{
    std::cout << "Ice type constructor called" << std::endl;
}

Ice::~Ice(void)
{
    std::cout << "Ice destructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &tmp)
{
    type = tmp.type;
    std::cout << "Ice Assignation operator called" << std::endl;
    return (*this);
}

AMteria *Ice::clone(void) const
{
    return (new Ice());
}

void    Ice::use(ICharacter &target)
{
    std::cout << "*shoots an ice bolt at " << target.getName() << "*" << std::endl;
}