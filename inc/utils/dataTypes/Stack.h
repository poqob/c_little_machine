#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 100 // Define a maximum size for the stack
#include <string.h>
#include <stdio.h>
typedef struct Stack
{
    char *data[MAX_SIZE];
    int top;
} Stack;

// Function prototypes
void initializeStack(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
void push(Stack *s, char *value);
char *pop(Stack *s);
char *peek(Stack *s);

#endif
