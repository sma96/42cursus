#include <iostream>
#include <iomanip>
#include <string>

void        toChar(const std::string str)
{
    int c;
    try{
        c = stoi(str);
    }
    catch (std::exception &)
    {
        std::cout << "char : impossible" << std::endl;
        return ;
    }
    if (c < 32 || c > 123)
        std::cout << "char : Non displayable" << std::endl;
    else
        std::cout << "char : " << "'" << static_cast<char>(stoi(str)) << "'" << std::endl;
}


void        toInt(const std::string str)
{
    long long i;
    try{
        i = stoll(str);
        if (i > 2147483647)
            i = 2147483647;
        else if (i < -2147482648)
            i = -2147483648;
        std::cout << "int : " << static_cast<int>(i) << std::endl;
    }
    catch (std::exception &)
    {
        std::cout << "int : impossible" << std::endl;
        return ;
    }
}

void        toDouble(const std::string str)
{
    double d;
    try{

        d = stod(str);
        std::cout << "double : " << d << std::endl;
    }
    catch (std::exception &)
    {
        std::cout << "double : impossible" << std::endl;
        return ;
    }
}

void        toFloat(const std::string str)
{
    float f;
    try{
        f = stof(str);
        std::cout << "float : " << f << 'f' << std::endl;
    }
    catch (std::exception &)
    {
        std::cout << "float : impossible" << std::endl;
        return ;
    }
}
int main(int argc, char **argv)
{
    if (argc == 2)
    {
        std::string str = static_cast<std::string>(argv[1]);
        std::cout << std::fixed << std::setprecision(1);
        toChar(str);
        toInt(str);
        toFloat(str);
        toDouble(str);
    }
}