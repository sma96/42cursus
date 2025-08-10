#include "Data.hpp"

int main(void)
{
    Data d;
    Data t("mac", 25);
    Data *ut;
    uintptr_t u;

    u = d.serialize(&t);
    std::cout << std::endl;
    std::cout << "t.name = " << t.getName() << std::endl << "t.age = " << t.getAge() << std::endl;
    std::cout << std::endl;
    std::cout << "t address  = " << &t << std::endl;
    std::cout << "t uintptr_t = " << u << std::endl;
    ut = d.deserialize(u);
    std::cout << "ut address = " << ut << std::endl;
    std::cout << std::endl;
    std::cout << "ut.name = " << ut->getName() << std::endl << "ut.age = " << ut->getAge() << std::endl;

    return (0);
}