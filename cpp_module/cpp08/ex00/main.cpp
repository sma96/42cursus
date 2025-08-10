#include "easyfine.hpp"

int main(void)
{
    std::vector<int> v;
    std::list<int> l;
    std::deque<int> d;
    // std::vector<int>::iterator iter = v.begin();

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    l.push_back(30);
    l.push_back(20);
    l.push_back(10);
    l.push_back(40);

    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_back(40);

    try{
        std::cout << *easyfind(l, 10) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}