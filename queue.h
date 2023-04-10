#include "list.h"

typedef struct Queue{
    Team *front, *rear;
}Queue;

Queue *createQueue();

void enQueue(Queue *q, Team *v);
Team *deQueue(Queue *q);

int isEmptyQueue(Queue *q);