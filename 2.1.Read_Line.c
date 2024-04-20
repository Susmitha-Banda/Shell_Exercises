#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prototype
 * Return: Always 0.
 */
int main(void)
{
    char *buffer = malloc(1024);
    size_t len = 1024;

    while (1)
    {
        printf("$ ");
        getline(&buffer, &len, stdin);
        printf("%s", buffer);
    }

    free(buffer);
    return (0);
}
