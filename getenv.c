#include <stdio.h>

// Declare the global variable 'environ'
extern char **environ;

// Custom getenv function
char *_getenv(const char *name) {
    // Iterate through the environ array
    for (int i = 0; environ[i] != NULL; i++) {
        // Check if the current environment variable starts with the specified name
        if (strncmp(environ[i], name, strlen(name)) == 0) {
            // If found, return a pointer to the value part of the environment variable
            return strchr(environ[i], '=') + 1;
        }
    }
    // If not found, return NULL
    return NULL;
}

int main() {
    // Test the custom getenv function
    const char *variable_name = "PATH";
    char *value = _getenv(variable_name);
    if (value != NULL) {
        printf("Value of %s: %s\n", variable_name, value);
    } else {
        printf("%s not found in the environment\n", variable_name);
    }

    return 0;
}

