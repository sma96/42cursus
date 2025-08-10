#ifndef MTERIASOURCE_HPP
#define MTERIASOURCE_HPP

#include "IMteriaSource.hpp"

class MteriaSource : public IMateriaSource{
    private:
        AMteria *a[4];

    public:
        MteriaSource(void);
        MteriaSource(const MteriaSource &tmp);
        MteriaSource(std::string const &name);
        ~MteriaSource(void);

        MteriaSource &operator=(const MteriaSource &tmp);

        void    learnMateria(AMteria* m);
        AMteria *createMateria(std::string const &type);
};

#endif