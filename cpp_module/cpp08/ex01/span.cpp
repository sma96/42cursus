#include "span.hpp"

Span::Span(void) : _capacity(0)
{
    v.reserve(_capacity);
}

Span::Span(const Span &tmp)
{
    *this = tmp;
}

Span::Span(unsigned int const N) : _capacity(N)
{
    v.reserve(_capacity);
}

Span::~Span(void)
{
    v.clear();
    std::vector<int>().swap(v);
    std::cout << "Span destructor called" << std::endl;
}

Span        &Span::operator=(const Span &tmp)
{
    _capacity = tmp._capacity;
    v.reserve(_capacity);
    std::copy(tmp.v.begin(), tmp.v.end(), v.begin());
    return (*this);
}

void        Span::addNumber(unsigned int const N)
{
    if (v.size() < _capacity)
        v.push_back(N);
    else
        throw FullStoredException();
}

unsigned int    Span::shortestSpan(void)
{
    if (v.size() < 2)
        throw NoSpanException();
    unsigned int u_max = UINT_MAX;
    std::vector<int>::iterator iter;
    std::sort(v.begin(), v.end());
    for (std::vector<int>::iterator iter = v.begin(); (iter + 1) != v.end(); iter++)
    {
        if (static_cast<unsigned int>(*(iter + 1) - *iter) < u_max)
            u_max = *(iter + 1) - *iter;
    }
    return (u_max);
}

unsigned int    Span::longestSpan(void)
{
    if (v.size() < 2)
        throw NoSpanException();
    std::sort(v.begin(), v.end());
    std::vector<int>::iterator iter = v.end();
    return (*(--iter) - (*v.begin()));
}

const char      *Span::FullStoredException::what(void) const throw()
{
    return ("full stored in vector");
}

const char      *Span::NoSpanException::what(void) const throw()
{
    return ("no span in vector");
}