#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

class NotFoundValue : public std::exception{
    public:
        const char* what() const throw()
        {
            return ("not found value in container");
        }
};

template <typename T>
typename T::iterator    easyfind(T &c, int value)
{
    typename T::iterator iter = std::find(c.begin(), c.end(), value);

    if (iter == c.end())
        throw NotFoundValue();
    return (iter);
}

#endif