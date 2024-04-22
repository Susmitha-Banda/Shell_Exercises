#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom function to print each directory in the PATH environment variable
void print_path_directories() {
    // Get the value of the PATH environment variable
    char *path = getenv("PATH");
    if (path == NULL) {
        printf("PATH environment variable not found.\n");
        return;
    }

    // Tokenize the PATH string using ':' as the delimiter
    char *token = strtok(path, ":");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, ":");
    }
}

int main() {
    // Call the function to print directories in the PATH environment variable
    printf("Directories in the PATH environment variable:\n");
    print_path_directories();

    return 0;
}

