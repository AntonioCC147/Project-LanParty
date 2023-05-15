#include "../main.h"
#include "../headers/queue.h"

Queue *createQueue(){
	Queue *queue = (Queue *)malloc(sizeof(Queue));

	if(queue == NULL)
		return NULL;
	queue->front = queue->rear = NULL;

	return queue;
}

int isEmptyQueue(Queue *queue){
	return (queue->front == NULL);
}

void enQueue(Queue *queue, Team *value){
	Team *newNode = (Team *)malloc(sizeof(Team));

	newNode->teamName = (char *)malloc(strlen(value->teamName) + 1);
    strcpy(newNode->teamName, value->teamName);

    newNode->teamMates = value->teamMates;
    newNode->totalPoints = value->totalPoints;
	newNode->val.points = value->val.points;

	newNode->val.firstName = (char *)malloc(strlen(value->val.firstName) + 1);
    strcpy(newNode->val.firstName, value->val.firstName);

	newNode->val.secondName = (char *)malloc(strlen(value->val.secondName) + 1);
    strcpy(newNode->val.secondName, value->val.secondName);

	newNode->next = NULL;
	if(queue->rear == NULL)
		queue->rear = newNode;
	else{
		(queue->rear)->next = newNode;
		(queue->rear) = newNode;
	}
	if(queue->front == NULL)
		queue->front = queue->rear;
}

void enQueueStack(Queue *queue, Stack *stack){
	Team *newNode = (Team *)malloc(sizeof(Team));

	newNode->teamName = (char *)malloc(strlen(stack->val.teamName) + 1);
    strcpy(newNode->teamName, stack->val.teamName);

    newNode->teamMates = stack->val.teamMates;
    newNode->totalPoints = stack->val.totalPoints;
	newNode->val.points = stack->val.val.points;

	newNode->val.firstName = (char *)malloc(strlen(stack->val.val.firstName) + 1);
    strcpy(newNode->val.firstName, stack->val.val.firstName);

	newNode->val.secondName = (char *)malloc(strlen(stack->val.val.secondName) + 1);
    strcpy(newNode->val.secondName, stack->val.val.secondName);

	newNode->next = NULL;
	if(queue->rear == NULL)
		queue->rear = newNode;
	else{
		(queue->rear)->next = newNode;
		(queue->rear) = newNode;
	}
	if(queue->front == NULL)
		queue->front = queue->rear;
}

void enQueueWinnerTeam(Queue *queue, Stack *stack){
    Team *newTeam = (Team *)malloc(sizeof(Team));

    newTeam->teamName = (char *)malloc(strlen(stack->val.teamName));
    strcpy(newTeam->teamName, stack->val.teamName);

    newTeam->teamMates = stack->val.teamMates;
    newTeam->totalPoints = stack->val.totalPoints;
	newTeam->val.points = stack->val.val.points;

    newTeam->val.firstName = (char *)malloc(strlen(stack->val.val.firstName) + 1);
    strcpy(newTeam->val.firstName, stack->val.val.firstName);

    newTeam->val.secondName = (char *)malloc(strlen(stack->val.val.secondName) + 1);
    strcpy(newTeam->val.secondName, stack->val.val.secondName);

    newTeam->next = queue->rear;
    queue->rear = newTeam;
}

Team *deQueue(Queue *queue){
	Queue aux; Team *team = (Team *)malloc(sizeof(Team));

	aux.front = queue->front;

	team->teamName = (char *)malloc(strlen(aux.front->teamName) + 1);
	strcpy(team->teamName, aux.front->teamName);

	team->teamMates = aux.front->teamMates;
	team->totalPoints = aux.front->totalPoints;
	team->val.points = aux.front->val.points;

	team->val.firstName = (char *)malloc(strlen(aux.front->val.firstName) + 1);
	strcpy(team->val.firstName, aux.front->val.firstName);
	team->val.secondName = (char *)malloc(strlen(aux.front->val.secondName) + 1);
	strcpy(team->val.secondName, aux.front->val.secondName);

	team->val = aux.front->val;
	queue->front = (queue->front)->next;

	free(aux.front);
	
	return team;
}

void deleteQueue(Queue *queue) {
    Team *current = queue->front, *next;

    while(current != NULL){
        next = current->next;

        free(current->teamName);
		free(current->val.firstName);
		free(current->val.secondName);
		free(current);

        current = next;
    }

    queue->front = NULL; queue->rear = NULL;
}
