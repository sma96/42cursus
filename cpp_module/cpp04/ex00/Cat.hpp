#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal{
    public:
        Cat(void);
        Cat(const Cat &tmp);
        Cat(const std::string name);
        ~Cat(void);

        Cat &operator=(const Cat &tmp);

        std::string getType(void) const;

        void makeSound(void) const;
};

#endif