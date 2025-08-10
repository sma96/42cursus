#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void)
{
    // const Animal *animal;
    // const Animal *animal = new Animal();
    const Animal *cat = new Cat();
    const Animal *dog = new Dog();

    cat->makeSound();
    dog->makeSound();

    delete cat;
    delete dog;

    return 0;
}