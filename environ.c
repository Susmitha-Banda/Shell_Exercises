#include <stdio.h>
#include <stdlib.h> // Include the declaration of the 'environ' variable

// Declare the 'environ' variable, which is defined in the <stdlib.h> header
extern char **environ;

int main(void)
{
    // Iterate over the 'environ' array until reaching a NULL pointer
    for (int i = 0; environ[i] != NULL; i++)
    {
        // Print each environment variable
        printf("%s\n", environ[i]);
    }

    return 0;
}

