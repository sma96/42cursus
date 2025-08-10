#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void    iter(T* array, unsigned int size, void(*f)(T arg))
{
    for (unsigned int i = 0; i < size; i++)
    {
        f(array[i]);
    }
}

template <typename T>
void    print(T arg)
{
    std::cout << arg << std::endl;
}

#endif