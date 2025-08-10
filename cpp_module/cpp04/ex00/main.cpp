#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
    std::cout << "-----------------------------------------" << std::endl;

    const Animal* meta = new Animal(); //const로 선언했을 경우 호출할 함수들도 const 함수로 선언ㄴ
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* t = new WrongCat();

    std::cout << "-----------------------------------------" << std::endl;

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << t->getType() << " " << std::endl;

    std::cout << "-----------------------------------------" << std::endl;

    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    t->makeSound();
    
    std::cout << "-----------------------------------------" << std::endl;

    delete i;
    delete j;
    delete t;

    std::cout << "-----------------------------------------" << std::endl;
    
    return (0);
}