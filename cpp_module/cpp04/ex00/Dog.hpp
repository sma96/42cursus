#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal{
    public:
        Dog(void);
        Dog(const Dog &tmp);
        Dog(const std::string name);
        ~Dog(void);

        Dog &operator=(const Dog &tmp);

        std::string getType(void) const;

        void makeSound(void) const;
};

#endif