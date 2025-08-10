#include "MteriaSource.hpp"

MteriaSource::MteriaSource(void)
{
    for (int i = 0; i < 4; i++)
    {
        a[i] = NULL;
    }
    std::cout << "MteriaSource default constructor called" << std::endl;
}

MteriaSource::MteriaSource(const MteriaSource &tmp)
{
    *this = tmp;
    std::cout << "MteriaSource copy constructor called" << std::endl;
}

MteriaSource::~MteriaSource(void)
{
    for (int i = 0; i < 4; i++)
    {
        if (a[i] != NULL)
        {
            delete a[i];
            a[i] = NULL;
        }
    }
    std::cout << "MteriaSource destructor called" << std::endl;
}

MteriaSource &MteriaSource::operator=(const MteriaSource &tmp)
{
    for (int i = 0; i < 4; i++)
    {
        if (a[i] != NULL)
        {
            delete a[i];
            a[i] = NULL;
        }
        a[i] = tmp.a[i]->clone();
    }
    std::cout << "Mteria Assignation operator called" << std::endl;
    return (*this);
}

void    MteriaSource::learnMateria(AMteria *m)
{
    if (!m)
        return ;
    for (int i = 0; i < 4; i++)
    {
        if (a[i] == NULL)
        {
            a[i] = m->clone();
            std::cout << "stored AMteria " << a[i]->getType() <<  std::endl;
            return ;
        }
    }
    std::cout << "AMteria is full, can't store AMteria" << std::endl;
}

AMteria *MteriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (a[i] != NULL && a[i]->getType() == type)
        {
            return (a[i]->clone());
        }
    }
    std::cout << "no match type in inventory" << std::endl;
    return (0);
}
