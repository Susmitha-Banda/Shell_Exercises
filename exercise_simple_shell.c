// Filename: simple_shell.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024

int main(void)
{
    char command[MAX_COMMAND_LENGTH];

    while (1)
    {
        printf("#cisfun$ ");
        fflush(stdout); // Flush the output buffer to ensure prompt is displayed

        if (fgets(command, sizeof(command), stdin) == NULL)
        {
            printf("\n"); // User entered EOF (Ctrl + D), print newline and exit
            break;
        }

        // Remove trailing newline character
        command[strcspn(command, "\n")] = '\0';

        pid_t child_pid = fork();
        if (child_pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (child_pid == 0)
        {
            // Child process
            execl(command, command, NULL);
            // If exec fails, print error message and exit child process
            perror(command);
            exit(EXIT_FAILURE);
        }
        else
        {
            // Parent process
            int status;
            wait(&status); // Wait for child process to finish

            // Check if child process terminated normally
            if (WIFEXITED(status))
            {
                printf("Child process exited with status %d\n", WEXITSTATUS(status));
            }
            else
            {
                printf("Child process exited abnormally\n");
            }
        }
    }

    return 0;
}

