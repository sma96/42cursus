#include "Character.hpp"

Character::Character(void) : name("defalut Character")
{
    for (int i = 0; i < 4; i++)
    {
        inventory[i] = NULL;
    }
    std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const Character &tmp)
{
    *this = tmp;
    std::cout << "Character copy constructor called" << std::endl;
}

Character::Character(std::string const &name) : name(name)
{
    for (int i = 0; i < 4; i++)
    {
        inventory[i] = NULL;
    }
    std::cout << "Character name constructor called" << std::endl;
}

Character::~Character(void)
{
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] != NULL)
        {
            delete inventory[i];
            inventory[i] = NULL;
        }
    }
    std::cout << "Character destructor called" << std::endl;
}

Character &Character::operator=(const Character &tmp)
{
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] != NULL)
        {
            delete inventory[i];
            inventory[i] = NULL;
        }
        if (tmp.inventory[i] != NULL)
            inventory[i] = tmp.inventory[i]->clone();
    }
    name = tmp.name;
    std::cout << "Character Assignation operator called" << std::endl;
    return (*this);
}

std::string const &Character::getName(void) const
{
    return (name);
}

void    Character::equip(AMteria *m)
{
    if (!m)
        return ;
    for (int i = 0; i < 4; i++)
    {
        
        if (inventory[i] == NULL)
        {
            inventory[i] = m;
            std::cout << "equipped with " << m->getType() << std::endl;
            return ;
        }
    }
    std::cout << "inventory is full, can't equip Materia" << std::endl;
}

void    Character::unequip(int idx)
{
    if (idx > 3 || idx < 0)
    {
        std::cout << "out of range idx" << std::endl;
        return ;
    }
    if (inventory[idx] != NULL)
    {
        std::cout << "unequipped : " << inventory[idx]->getType() << std::endl;
        inventory[idx] = NULL;
        return ;
    }
    std::cout << "unequip : nothing in inventory" << std::endl;
}

void    Character::use(int idx, ICharacter &target)
{
    if (idx < 4 && idx >= 0)
    {
        if (inventory[idx])
            inventory[idx]->use(target);
        else
            std::cout << "use : nothing in inventory" << std::endl;
    }
}

void    Character::getInventory(void) const
{
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] != NULL)
            std::cout << getName() << " inventory [" << i << "] = " << inventory[i]->getType() << std::endl;
        else 
            std::cout << getName() <<  " inventory [" << i << "] = " << "NULL" << std::endl;    
    }
}
