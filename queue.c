#include "main.h"
#include "./libraries/queue.h"

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
	newNode->val.points = v->val.points;

	newNode->val.firstName = (char *)malloc(strlen(v->val.firstName) + 1);
    strcpy(newNode->val.firstName, v->val.firstName);

	newNode->val.secondName = (char *)malloc(strlen(v->val.secondName) + 1);
    strcpy(newNode->val.secondName, v->val.secondName);

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

void enQueueStack(Queue *q, Stack *v){
	Team *newNode = (Team *)malloc(sizeof(Team));

	newNode->teamName = (char *)malloc(strlen(v->val.teamName) + 1);
    strcpy(newNode->teamName, v->val.teamName);

    newNode->teamMates = v->val.teamMates;
    newNode->totalPoints = v->val.totalPoints;
	newNode->val.points = v->val.val.points;

	newNode->val.firstName = (char *)malloc(strlen(v->val.val.firstName) + 1);
    strcpy(newNode->val.firstName, v->val.val.firstName);

	newNode->val.secondName = (char *)malloc(strlen(v->val.val.secondName) + 1);
    strcpy(newNode->val.secondName, v->val.val.secondName);

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

void enQueueWinnerTeam(Queue *q, Stack *s){
    Team *newTeam = (Team *)malloc(sizeof(Team));

    newTeam->teamName = (char *)malloc(strlen(s->val.teamName));
    strcpy(newTeam->teamName, s->val.teamName);

    newTeam->teamMates = s->val.teamMates;
    newTeam->totalPoints = s->val.totalPoints;
	newTeam->val.points = s->val.val.points;

    newTeam->val.firstName = (char *)malloc(strlen(s->val.val.firstName) + 1);
    strcpy(newTeam->val.firstName, s->val.val.firstName);

    newTeam->val.secondName = (char *)malloc(strlen(s->val.val.secondName) + 1);
    strcpy(newTeam->val.secondName, s->val.val.secondName);

    newTeam->next = q->rear;
    q->rear = newTeam;
}

Team *deQueue(Queue *q){
	Queue aux;
	Team *d = (Team *)malloc(sizeof(Team));

	aux.front = q->front;

	d->teamName = (char *)malloc(strlen(aux.front->teamName) + 1);
	strcpy(d->teamName, aux.front->teamName);

	d->teamMates = aux.front->teamMates;
	d->totalPoints = aux.front->totalPoints;
	d->val.points = aux.front->val.points;

	d->val.firstName = (char *)malloc(strlen(aux.front->val.firstName) + 1);
	strcpy(d->val.firstName, aux.front->val.firstName);
	d->val.secondName = (char *)malloc(strlen(aux.front->val.secondName) + 1);
	strcpy(d->val.secondName, aux.front->val.secondName);

	d->val = aux.front->val;
	q->front = (q->front)->next;

	free(aux.front);
	
	return d;
}

int isEmptyQueue(Queue *q){
	return(q->front == NULL);
}

void deleteQueue(Queue *q) {
    if (q == NULL)
        return;

    Team *current = q->front;
    Team *next;

    while(current != NULL){
        next = current->next;

        free(current->teamName);
        free(current->val.firstName);
        free(current->val.secondName);

        free(current);

        current = next;
    }

    q->front = NULL; q->rear = NULL;
}
