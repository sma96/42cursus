#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog"), brain(new Brain())
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &tmp) : Animal(tmp.type)
{
	*(this->brain) = *(tmp.brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::Dog(const std::string name) : Animal(name), brain(new Brain())
{
	std::cout << "Dog name constructor called" << std::endl;
}

Dog::~Dog(void)
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &tmp)
{
	Animal::operator=(tmp);
	this->type = tmp.type;
	*(this->brain) = *(tmp.brain);
	std::cout << "Dog Assignation operator called" << std::endl;
	return (*this);
}

std::string Dog::getType(void) const
{
	return (type);
}

Brain   *Dog::getBrain(void) const
{
    return (this->brain);
}

std::string Dog::getIdeas(const int index) const
{
	if (index > 99 || index < 0)
        return (0);
	return (brain->getIdeas(index));
}

void	Dog::setIdeas(const int index, const std::string idea)
{
	if (index > 99 || index < 0)
        return ;
	brain->setIdeas(index, idea);
}

void	Dog::makeSound(void) const
{
	std::cout << type << " : 멍멍" << std::endl;
}

