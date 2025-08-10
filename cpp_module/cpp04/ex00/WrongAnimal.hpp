#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal{
    protected:
        std::string type;

    public:
        WrongAnimal(void);
        WrongAnimal(const std::string name);
        virtual ~WrongAnimal(void); // 부모클래스 포인터에 자식클래스 객체를 대입해줄 때 소멸자를 
                                // 가상함수로 선언해줘야 자식까지 소멸자가 호출 가능하다
        std::string getType(void) const;

        virtual void makeSound(void) const;
};

#endif