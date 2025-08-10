#include "Zombie.hpp"

zombie::zombie(void)
{

}

zombie::~zombie(void)
{
    std::cout << name << " is died" << std::endl;
}

void    zombie::announce(void)
{
    std::cout << this->name << " braiiiinnnzzzz" << std::endl;
}

void	zombie::setName(std::string str)
{
    name = str;
}

std::string make_num(int num)
{
    int i;
    int len;
    int c_num;
    std::string str;
    std::string str2;

    i = 0;
    len = 0;
    c_num = num;
    if (c_num == 0)
        len = 1;
    while (c_num)
    {
        c_num = c_num / 10;
        len++;
    }
    std::cout << len << std::endl;
    int arr[len];
    while (i < len)
    {
        arr[i] = num % 10;
        num = num / 10;
        i++;
    }
    if (len > 1)
    {
        str = arr[--len] + '0';
        str2 = arr[--len] + '0';
    }
    else
    {
        str = arr[--len] + '0';
        return str;
    }
    while (len >= 0)
    {
        str = str + str2;
        str2 = arr[--len] + '0';
    }
    return (str);
}
zombie  *zombiehorde(int n, std::string name)
{
    int i;
    zombie *z = new zombie[n];
    std::string num;

    i = 0;
    while (i < n)
    {
        num = make_num(i);
        // num = i + '0';
        z[i].setName(name + num);
        i++;
    }
    return (z);
}


int main(void)
{
    zombie *z;

    z = zombiehorde(123, "zombie");
    for (int i = 0; i < 123; i++)
    {
        z[i].announce();
    }
    delete [] z;
    return (0);
}