#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <algorithm>

template <typename T>
class MutantStack: public std::stack<T>{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;

        MutantStack(void) : std::stack<T>(){}
        MutantStack(const MutantStack &tmp) : std::stack<T>(tmp)
        {
            *this = tmp;
        }
        ~MutantStack(void){}

        MutantStack &operator=(const MutantStack &tmp)
        {
            this->c = tmp.c;
            return (*this);
        }

        iterator    begin(void)
        {
            return (this->c.begin());
        }
        iterator    end(void)
        {
            return (this->c.end());
        }
};

#endif