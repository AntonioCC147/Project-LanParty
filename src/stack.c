#include "../main.h"
#include "../headers/stack.h"

int isEmptyStack(Team *top){
	return (top == NULL);
}

void createStack(Stack **top, Team *value){
    Stack *newNode = (Stack *)malloc(sizeof(Stack));
    if(newNode == NULL){
        printf("Allocation error!"); exit(1);
    }

    newNode->val.teamMates = value->teamMates;
    newNode->val.totalPoints = value->totalPoints;

    newNode->val.teamName = (char *)malloc(strlen(value->teamName));
    strcpy(newNode->val.teamName, value->teamName);

    newNode->val.val.firstName = (char *)malloc(strlen(value->val.firstName) + 1);
    strcpy(newNode->val.val.firstName, value->val.firstName);

    newNode->val.val.secondName = (char *)malloc(strlen(value->val.secondName) + 1);
    strcpy(newNode->val.val.secondName, value->val.secondName);

    newNode->val.val.points = value->val.points;

    newNode->next = (*top);
    (*top) = newNode;
}

void deleteStack(Stack **top){
	Stack *topcopy;

    while(*top != NULL){
        topcopy = (*top)->next;
        free(*top);
        *top = topcopy;
    }
    
    *top = NULL;
}