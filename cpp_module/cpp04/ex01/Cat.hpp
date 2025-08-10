#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
    private:
        Brain   *brain;

    public:
        Cat(void);
        Cat(const Cat &tmp);
        Cat(const std::string name);
        ~Cat(void);

        Cat &operator=(const Cat &tmp);

        std::string getType(void) const;
        Brain   *getBrain(void) const;
        std::string getIdeas(const int index) const;
        void    setIdeas(const int index, const std::string idea);
        
        void makeSound(void) const;
};

#endif