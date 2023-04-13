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

void enQueueWinnerTeam(Queue *q, Stack *s){
    if (q == NULL || s == NULL || s->val.teamName == NULL || s->val.val.firstName == NULL || s->val.val.secondName == NULL) {
        // Handle NULL pointers, e.g., return an error or exit gracefully
        printf("Invalid input\n");
        return;
    }

    Team *newNode = (Team *)malloc(sizeof(Team));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->teamMates = s->val.teamMates;

    newNode->teamName = (char *)malloc(strlen(s->val.teamName) + 1);
    if (newNode->teamName == NULL) {
        free(newNode); // Free previously allocated memory
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(newNode->teamName, s->val.teamName);

    newNode->totalPoints = s->val.totalPoints;

    newNode->val.firstName = (char *)malloc(strlen(s->val.val.firstName) + 1);
    if (newNode->val.firstName == NULL) {
        free(newNode->teamName); // Free previously allocated memory
        free(newNode); // Free previously allocated memory
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(newNode->val.firstName, s->val.val.firstName);

    newNode->val.secondName = (char *)malloc(strlen(s->val.val.secondName) + 1);
    if (newNode->val.secondName == NULL) {
        free(newNode->val.firstName); // Free previously allocated memory
        free(newNode->teamName); // Free previously allocated memory
        free(newNode); // Free previously allocated memory
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(newNode->val.secondName, s->val.val.secondName);

    newNode->val.points = s->val.val.points;

    newNode->next = NULL;

    if (q->rear == NULL)
        q->rear = newNode;
    else {
        (q->rear)->next = newNode;
        q->rear = newNode;
    }

    if (q->front == NULL)
        q->front = q->rear;
}

Team *deQueue(Queue *q){
	Queue aux;
	Team *d = (Team *)malloc(sizeof(Team));

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

int isEmptyQueue(Queue *q){
	return(q->front == NULL);
}

void deleteQueue(Queue *q) {
    if (q == NULL) {
        return; // Nothing to delete
    }

    Team *current = q->front;
    Team *next;

    while (current != NULL) {
        next = current->next;

        // Free dynamically allocated strings in the Team struct
        free(current->teamName);
        free(current->val.firstName);
        free(current->val.secondName);

        // Free the Team struct itself
        free(current);

        current = next;
    }

    // Set front and rear pointers to NULL to indicate an empty queue
    q->front = NULL;
    q->rear = NULL;
}
