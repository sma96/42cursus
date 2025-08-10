#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array{
    private:
        T*              array;
        unsigned int    size;
    
    public:
        Array(void) : array(NULL), size(0)
        {
            std::cout << "Array default constructor called" << std::endl;
        }
        Array(unsigned int n) : size(n)
        {
            if (n < 0)
            {
                array = NULL;
                size = 0;
            }
            else
                array = new T[size]();
            std::cout << "Array size constructor called" << std::endl;
        }
        Array(const Array &tmp) : array(NULL), size(0)
        {
            *this = tmp;
            std::cout << "Array copy constructor called" << std::endl;
        }
        ~Array(void)
        {
            delete [] array;
            std::cout << "Array destructor called" << std::endl;
        }

        Array &operator=(const Array &tmp)
        {
            if (size > 0)
            {
                delete [] array;
                array = NULL;
            }
            if (tmp.size > 0)
            {
                array = new T[tmp.size]();
                for (unsigned int i = 0; i < tmp.size; i++)
                    array[i] = tmp.array[i];
                size = tmp.size;
            }
            else
            {
                size = 0;
            }
            std::cout << "Array Assignation operator called" << std::endl;
            return (*this);
        }

        T    &operator[](unsigned int idx)
        {
            if (idx >= size || idx < 0)
                throw AccessNonAllocatedMemory();
            return (array[idx]);
        }

        T const    &operator[](unsigned int idx) const
        {
            return (operator[](idx));
        }

        unsigned int    _size(void) const
        {
            return (size);
        }

        class AccessNonAllocatedMemory : public std::exception{
            const char* what() const throw()
            {
                return ("access non allocated memory");
            }
        };
};

#endif