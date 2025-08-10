#include "Bureaucrat.hpp"

int main(void)
{
    try{
        Bureaucrat B("sma", 1);
        B.increment();
        std::cout << B << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}