#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data{
    private:
        std::string name;
        int         age;
    
    public:
        Data(void);
        Data(const Data &tmp);
        Data(std::string const &name, int const &age);
        ~Data(void);

        Data &operator=(const Data &tmp);

        std::string const   &getName(void) const;
        int const           &getAge(void) const;

        uintptr_t           serialize(Data *ptr);
        Data                *deserialize(uintptr_t raw);// uintptr_t 타입은 포인터의 주소를 저장하는 타입이다. uintptr_t는 부호가 없는 타입
};

#endif