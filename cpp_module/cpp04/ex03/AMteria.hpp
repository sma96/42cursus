#ifndef AMTERIA_HPP
#define AMTERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMteria{
    protected:
        std::string type;
    
    public:
        AMteria(std::string const &type);
        AMteria(const AMteria &tmp);
        virtual ~AMteria(void);

        AMteria &operator=(const AMteria &tmp);

        std::string const &getType(void) const;
        
        virtual AMteria *clone(void) const =0;
        virtual void    use(ICharacter &target);
};

#endif