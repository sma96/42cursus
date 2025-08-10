#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main(void)
{
    int n = 4;
    const Animal *animals[n];

    for(int i = 0; i < n / 2; i++)
    {
        animals[i] = new Dog();
    }
    for(int i = 2; i < n; i++)
    {
        animals[i] = new Cat();
    }
    Cat cat1;
    Cat cat2;
    cat1.setIdeas(0, "i am cat");
    cat2.setIdeas(0 ,"i am tiger");
    std::cout << cat1.getIdeas(0) << std::endl;
    std::cout << cat2.getIdeas(0) << std::endl;

    for(int i = 0; i < n; i++)
    {
        delete(animals[i]);
    }
    return 0;
}