#include "../../../inc/utils/dataTypes/Stack.h"
#include <stdlib.h> // Include for memory allocation

// Function implementations

void initializeStack(Stack *s)
{
    s->top = -1; // Initialize top to -1 indicating an empty stack
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int isFull(Stack *s)
{
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, char *value)
{
    if (isFull(s))
    {
        printf("Stack Overflow\n");
        return;
    }
    // Allocate memory for the string on the heap
    s->data[++s->top] = (char *)malloc(sizeof(char) * (strlen(value) + 1));
    strcpy(s->data[s->top], value); // Copy the string to the allocated memory
}

char *pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow\n");
        return NULL; // Indicate error or a null pointer
    }
    char *temp = s->data[s->top--]; // Store the top element
    free(temp);                     // Free the allocated memory
    return temp;                    // Return the popped string
}

char *peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is Empty\n");
        return NULL; // Indicate error or a null pointer
    }
    return s->data[s->top]; // Return the top element without removing it
}
