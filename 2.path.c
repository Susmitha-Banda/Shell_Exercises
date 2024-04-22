#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for a linked list node
typedef struct Node {
    char *directory;
    struct Node *next;
} Node;

// Function to create a new node
Node *createNode(char *directory) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->directory = strdup(directory); // Copy the directory string
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertNode(Node **head, char *directory) {
    Node *newNode = createNode(directory);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to build a linked list of PATH directories
Node *buildPathList() {
    char *path = getenv("PATH");
    if (path == 

