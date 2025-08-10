#include "Cure.hpp"

Cure::Cure(void) : AMteria("cure")
{
    std::cout <<  "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &tmp) : AMteria(tmp.type)
{
    std::cout << "Cure copy constructor called" << std::endl;
}

Cure::Cure(std::string const &type) : AMteria(type)
{
    std::cout << "Cure type constructor called" << std::endl;
}

Cure::~Cure(void)
{
    std::cout << "Cure destructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &tmp)
{
    type = tmp.type;
    std::cout << "Cure Assignation operator called" << std::endl;
    return (*this);
}

AMteria *Cure::clone(void) const
{
    return (new Cure());
}

void    Cure::use(ICharacter &target)
{
    std::cout << "*heals " << target.getName() << "'s wounds*" << std::endl;
}