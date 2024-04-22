#include <stdio.h>

// Declare the global variable 'environ'
extern char **environ;

int main(int argc, char *argv[], char *env[])
{
    // Print the addresses of 'env' and 'environ'
    printf("Address of env (third parameter of main): %p\n", (void *)env);
    printf("Address of environ (global variable): %p\n", (void *)environ);

    // Check if the addresses are the same
    if (env == environ)
    {
        printf("The addresses of env and environ are the same.\n");
    }
    else
    {
        printf("The addresses of env and environ are different.\n");
    }

    return 0;
}

