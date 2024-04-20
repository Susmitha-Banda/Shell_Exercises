#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **av)
{
    int i = 1; // Start from 1 to skip the program name (av[0])

    while (av[i] != NULL)
    {
        printf("%s\n", av[i]);
        i++;
    }

    return 0;
}

