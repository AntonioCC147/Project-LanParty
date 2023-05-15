#include "list.h"
#include "stack.h"

typedef struct Queue{
    Team *front, *rear;
}Queue;

Queue *createQueue();

int isEmptyQueue(Queue *queue);

void enQueue(Queue *queue, Team *value);
void enQueueStack(Queue *queue, Stack *value);
void enQueueWinnerTeam(Queue *queue, Stack *stack);

Team *deQueue(Queue *queue);
void deleteQueue(Queue *queue);