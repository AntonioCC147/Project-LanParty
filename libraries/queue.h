#include "list.h"
#include "stack.h"

typedef struct Queue{
    Team *front, *rear;
}Queue;

Queue *createQueue();

int isEmptyQueue(Queue *q);

void enQueue(Queue *q, Team *v);
void enQueueStack(Queue *q, Stack *v);
void enQueueWinnerTeam(Queue *q, Stack *s);

Team *deQueue(Queue *q);
void deleteQueue(Queue *q);