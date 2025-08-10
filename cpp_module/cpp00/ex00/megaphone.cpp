#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    int i;
    int j;

    i = 0;
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    while (argv[++i])
    {
        j = -1;
        while (argv[i][++j])
            std::cout << (char)std::toupper(argv[i][j]);
    }
    std::cout << std::endl;
    return (1);
}