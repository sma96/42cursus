#include "iter.hpp"

int main(void)
{
    int array[] = {1, 34, 23, 15, 67};
    char array1[] = {'c', 'a', 's', 'r', 'e'};
    iter(array1, 5, print);
    iter(array, 5, print);

    return (0);
}