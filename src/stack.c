#include "../main.h"
#include "../headers/stack.h"

int isEmptyStack(Team *top){
	return top == NULL;
}

void createStack(Stack **top, Team *v){
    Stack *newNode = (Stack *)malloc(sizeof(Stack));
    if(newNode == NULL){
        printf("Memory allocation failed\n"); exit(1);
    }

    newNode->val.teamMates = v->teamMates;
    newNode->val.totalPoints = v->totalPoints;

    newNode->val.teamName = (char *)malloc(strlen(v->teamName));
    strcpy(newNode->val.teamName, v->teamName);

    newNode->val.val.firstName = (char *)malloc(strlen(v->val.firstName) + 1);
    strcpy(newNode->val.val.firstName, v->val.firstName);

    newNode->val.val.secondName = (char *)malloc(strlen(v->val.secondName) + 1);
    strcpy(newNode->val.val.secondName, v->val.secondName);

    newNode->val.val.points = v->val.points;

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