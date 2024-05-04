#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h> // Include for memory allocation
#include <string.h>
typedef struct Queue
{
    char **data;  // Array of pointers to char
    int capacity; // Maximum capacity of the queue
    int front, rear;
    int size;
} Queue;

// Function prototypes
void initializeQueue(Queue *q, int initial_capacity);
int isEmptyQueue(Queue *q);
int isFullQueue(Queue *q);
void enqueueQueue(Queue *q, char *value);
char *dequeueQueue(Queue *q);
char *peekQueue(Queue *q);
void resizeQueue(Queue *q, int new_capacity); // Function for resizing

#endif
