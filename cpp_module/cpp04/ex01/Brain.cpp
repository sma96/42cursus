#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &tmp)
{
    *this = tmp;
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain(void)
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain   &Brain::operator=(const Brain &tmp)
{
    int i;
    
    i = -1;
    while (++i < 100)
    {
        this->ideas[i] = tmp.ideas[i];
    }
    std::cout << "Brain Assignation operator called" << std::endl;
    return (*this);
}

std::string Brain::getIdeas(int index) const
{
    if (index > 99 || index < 0)
        return (0);
    return (ideas[index]);
}

void    Brain::setIdeas(int index, const std::string idea)
{
    if (index > 99 || index < 0)
        return ;
    ideas[index] = idea;
}