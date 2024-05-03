#include "../../../inc/utils/dataTypes/Queue.h"
#include <stdlib.h> // Include for memory allocation
#include <stdio.h>

// Function implementations

void initializeQueue(Queue *q, int initial_capacity)
{
    q->data = (char **)malloc(sizeof(char *) * initial_capacity); // Allocate memory for data pointers
    q->capacity = initial_capacity;
    q->front = q->rear = -1; // Initialize front and rear to -1 indicating an empty queue
    q->size = 0;
}

int isEmptyQueue(Queue *q)
{
    return q->front == -1;
}

int isFullQueue(Queue *q)
{
    return q->rear == q->capacity - 1;
}

void enqueueQueue(Queue *q, char *value)
{
    if (isFull(q))
    {
        resizeQueue(q, q->capacity * 2); // Double the capacity if full
    }
    q->data[++q->rear] = (char *)malloc(sizeof(char) * (strlen(value) + 1)); // Allocate for string
    strcpy(q->data[q->rear], value);                                         // Copy the string
    q->size++;
}

char *dequeueQueue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow\n");
        return NULL; // Indicate error or a null pointer
    }
    char *temp = q->data[q->front]; // Store the front element
                                    // Free the allocated memory for the string
    if (q->size > 0)
    {
        free(temp);
    }
    return "deque"; // Return the dequeued string (needs to be freed by the user)
}

char *peekQueue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty\n");
        return NULL; // Indicate error or a null pointer
    }
    return q->data[q->rear]; // Return the front element without removing it
}

void resizeQueue(Queue *q, int new_capacity)
{
    char **temp = (char **)malloc(sizeof(char *) * new_capacity); // Allocate temporary array
    for (int i = 0; i <= q->rear; i++)
    { // Copy elements from old to new
        temp[i] = q->data[i];
    }
    free(q->data);              // Free old memory
    q->data = temp;             // Update data pointer to new array
    q->capacity = new_capacity; // Update capacity
}
