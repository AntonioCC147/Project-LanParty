#include "list.h"
#include "stack.h"

typedef struct Queue{
    Team *front, *rear;
}Queue;

Queue *createQueue();

void enQueue(Queue *q, Team *v);
void enQueueWinnerTeam(Queue *q, Stack *s);

void updateTeamListQueue(Queue *teamListQueue, Stack *winnerTeam);//

Team *deQueue(Queue *q);

int isEmptyQueue(Queue *q);

void deleteQueue(Queue *q);