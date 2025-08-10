#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat"), brain(new Brain())
{
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &tmp) : Animal(tmp.type)
{
    *(this->brain) = *(tmp.brain);
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::Cat(const std::string name) : Animal(name), brain(new Brain())
{
    std::cout << "Cat name constructor called" << std::endl;
}

Cat::~Cat(void)
{
    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &tmp)
{
    Animal::operator=(tmp);
    type = tmp.type;
    *(this->brain) = *(tmp.brain);
    std::cout << "Cat Assignation operator called" << std::endl;
    return (*this);
}

std::string     Cat::getType(void) const
{
    return (type);
}

Brain   *Cat::getBrain(void) const
{
    return (this->brain);
}

std::string Cat::getIdeas(const int index) const
{
    if (index > 99 || index < 0)
        return (0);
    return (brain->getIdeas(index));
}

void    Cat::setIdeas(const int index, const std::string idea)
{
    if (index > 99 || index < 0)
        return ;
    brain->setIdeas(index, idea);
}

void    Cat::makeSound(void) const
{
    std::cout << type << " : 야옹" << std::endl;
}