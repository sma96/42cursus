#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain{
    protected:
        std::string ideas[100];
    
    public:
        Brain(void);
        Brain(const Brain &tmp);
        ~Brain(void);

        Brain   &operator=(const Brain &tmp);

        std::string getIdeas(int index) const;
        void    setIdeas(int index, const std::string idea);
};

#endif