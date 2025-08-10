#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <random>

Base    *generate(void)
{
    srand(time(NULL));
    if (rand() % 10 < 3)
    {
        std::cout << "generated A" << std::endl;
        return (dynamic_cast<Base *>(new A()));
    }
    else if (rand() % 10 < 6)
    {
        std::cout << "generated B" << std::endl;
        return (dynamic_cast<Base *>(new B()));
    }
    else
    {
        std::cout << "generated C" << std::endl;
        return (dynamic_cast<Base *>(new C()));
    }
}

void    identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "identify : A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "identify : B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "identify : C" << std::endl;
}

void    identify(Base &p)
{
    try {
        A   &a = dynamic_cast<A &>(p);
        std::cout << "identify : A" << std::endl;
        (void)a;
    }
    catch (std::exception &e)
    {
        std::cout << "not A : " << e.what() << std::endl;
    }
    try {
        B   &b = dynamic_cast<B &>(p);
        std::cout << "identify : B" << std::endl;
        (void)b;
    }
    catch (std::exception &e)
    {
        std::cout << "not B : " << e.what() << std::endl;
    }
    try {
        C   &c = dynamic_cast<C &>(p);
        std::cout << "identify : C" << std::endl;
        (void)c;
    }
    catch (std::exception &e)
    {
        std::cout << "not C : " << e.what() << std::endl;
    }
}

int main(void)
{
    Base *a = generate();

    identify(a);
    std::cout << std::endl;
    Base *b = generate();
    Base &c = *b;

    identify(c);
    std::cout << std::endl;
    delete b;
    delete a;
    return (0);
}