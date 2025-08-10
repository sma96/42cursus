#include "AMteria.hpp"

AMteria::AMteria(const AMteria &tmp) : type(tmp.type)
{
    std::cout << "AMteria copy constructor called" << std::endl;
}

AMteria::AMteria(std::string const &type) : type(type)
{
    std::cout << "AMteria type constructor called" << std::endl;
}

AMteria::~AMteria(void)
{
    std::cout << "AMteria destructor called" << std::endl;
}

AMteria &AMteria::operator=(const AMteria &tmp)
{
    type = tmp.type;
    std::cout << "AMteria Assignation operator called" << std::endl;
    return (*this);
}

std::string const &AMteria::getType(void) const
{
    return (type);
}

void    AMteria::use(ICharacter &target)
{
    std::cout << "Materia use" << target.getName() << std::endl;
}