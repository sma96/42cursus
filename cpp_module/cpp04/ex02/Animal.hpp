#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal{
    protected:
        std::string type;

    public:
        Animal(void);
        Animal(const Animal &tmp);
        Animal(const std::string name);
        virtual ~Animal(void); // 부모클래스 포인터에 자식클래스 객체를 대입해줄 때 소멸자를 
                                // 가상함수로 선언해줘야 자식까지 소멸자가 호출 가능하다
        Animal &operator=(const Animal &tmp);

        std::string getType(void) const;

        virtual void makeSound(void) const =0;
};

#endif