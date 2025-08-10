#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include <exception>

class Span{
    private:
        std::vector<int> v;
        unsigned int _capacity;


    public:
        Span(void);
        Span(unsigned int N);
        Span(const Span &tmp);
        ~Span(void);

        Span &operator=(const Span &tmp);

        void            addNumber(unsigned int const N);
        unsigned int    shortestSpan(void);
        unsigned int    longestSpan(void);

        class FullStoredException : public std::exception{
            const char *what() const throw();
        };
        class NoSpanException : public std::exception{
            const char *what() const throw();
        };

};

#endif