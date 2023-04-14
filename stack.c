#include "main.h"
#include "stack.h"

void createStack(Stack **top, Team *v) {
    if (v == NULL || v->teamName == NULL || v->val.firstName == NULL || v->val.secondName == NULL) {
        // Handle NULL pointers, e.g., return an error or exit gracefully
        printf("Invalid input\n");
        return;
    }

    Stack *newNode = (Stack *)malloc(sizeof(Stack));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
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

int isEmptyStack(Team *top){
	return top == NULL;
}

void deleteStack(Stack **top){
	Stack *topcopy;

    while (*top != NULL)
    {
        topcopy = (*top)->next;
        free(*top);
        *top = topcopy;
    }
    *top = NULL;
}

void displayStack(Stack *top) {
    printf("Printing stack:\n");
    while (top != NULL) {
        printf("Team Name: %s\n", top->val.teamName);
        top = top->next;
    }
}