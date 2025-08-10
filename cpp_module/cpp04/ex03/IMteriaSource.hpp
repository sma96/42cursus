#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMteria.hpp"

class IMateriaSource{
    public:
        virtual ~IMateriaSource(void) {}

        virtual void learnMateria(AMteria *m) =0;
        virtual AMteria *createMateria(std::string const &type) =0;
};

#endif