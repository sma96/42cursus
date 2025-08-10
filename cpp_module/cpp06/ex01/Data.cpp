#include "Data.hpp"

Data::Data(void) : name("sma"), age(27)
{
}

Data::Data(const Data &tmp)
{
    *this = tmp;
    std::cout << "Data copy constructor called" << std::endl;
}

Data::Data(std::string const &name, int const &age) : name(name), age(age)
{
    std::cout << "Data name constructor called" << std::endl;
}

Data::~Data(void)
{
    std::cout << "Data destructor called" << std::endl;
}

Data    &Data::operator=(const Data &tmp)
{
    name = tmp.name;
    age = tmp.age;
    return (*this);
}

std::string const &Data::getName(void) const
{
    return (name);
}

int         const &Data::getAge(void) const
{
    return (age);
}

uintptr_t   Data::serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data        *Data::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}