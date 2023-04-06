#include "main.h"
#include "queue.h"

Queue *createQueue(){
	Queue *q;
	q = (Queue *)malloc(sizeof(Queue));
	if(q == NULL)
		return NULL;
	q->front = q->rear = NULL;
	return q;
}

void enQueue(Queue *q, Team *v){
	Team *newNode = (Team *)malloc(sizeof(Team));

	newNode->teamName = (char *)malloc(strlen(v->teamName) + 1);
    strcpy(newNode->teamName, v->teamName);

    newNode->teamMates = v->teamMates;
    newNode->totalPoints = v->totalPoints;

	newNode->val.firstName = (char *)malloc(strlen(v->val.firstName) + 1);
    strcpy(newNode->val.firstName, v->val.firstName);
	newNode->val.secondName = (char *)malloc(strlen(v->val.secondName) + 1);
    strcpy(newNode->val.secondName, v->val.secondName);

	newNode->val.points = v->val.points;

	newNode->next = NULL;
	if(q->rear == NULL)
		q->rear = newNode;
	else{
		(q->rear)->next = newNode;
		(q->rear) = newNode;
	}
	if(q->front == NULL)
		q->front = q->rear;
}

Team *deQueue(Queue *q){
	Queue aux;
	Team *d = (Team *)malloc(sizeof(Team));

	//if(isEmpty(q) == 0)
		//return 0;

	aux.front = q->front;

	d->teamName = (char *)malloc(strlen(aux.front->teamName) + 1);
	strcpy(d->teamName, aux.front->teamName);

	d->teamMates = aux.front->teamMates;
	d->totalPoints = aux.front->totalPoints;

	d->val.firstName = (char *)malloc(strlen(aux.front->val.firstName) + 1);
	strcpy(d->val.firstName, aux.front->val.firstName);
	d->val.secondName = (char *)malloc(strlen(aux.front->val.secondName) + 1);
	strcpy(d->val.secondName, aux.front->val.secondName);
	d->val.points = aux.front->val.points;

	d->val = aux.front->val;
	q->front = (q->front)->next;

	free(aux.front);
	
	return d;
}

int isEmpty(Queue *q){
	return(q->front == NULL);
}