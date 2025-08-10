#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter{
    private:
        std::string name;
        AMteria *inventory[4];

    public:
        Character(void);
        Character(const Character &tmp);
        Character(std::string const &name);
        ~Character(void);

        Character &operator=(const Character &tmp);

        std::string const &getName(void) const;
        void    getInventory(void) const;
        
        void    equip(AMteria *m);
        void    unequip(int idx);
        void    use(int idx, ICharacter &target);

};

#endif