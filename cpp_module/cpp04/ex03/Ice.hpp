#ifndef ICE_HPP
#define ICE_HPP

#include "AMteria.hpp"

class Ice : public AMteria{
    public:
        Ice(void);
        Ice(const Ice &tmp);
        Ice(std::string const &type);
        ~Ice(void);

        Ice &operator=(const Ice &tmp);

        AMteria *clone(void) const;
        void    use(ICharacter &target);
};

#endif