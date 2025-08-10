#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
    private:
        Brain   *brain;

    public:
        Dog(void);
        Dog(const Dog &tmp);
        Dog(const std::string name);
        ~Dog(void);

        Dog &operator=(const Dog &tmp);

        std::string getType(void) const;
        Brain *getBrain(void) const;
        std::string getIdeas(const int index) const;
        void    setIdeas(const int index, const std::string idea);
        
        void makeSound(void) const;
};

#endif