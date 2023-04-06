#include "main.h"
#include "stack.h"

void push(Team **top, Team *v){
	Team *newNode = (Team *)malloc(sizeof(Team));

    newNode->teamMates = v->teamMates;

    newNode->teamName = (char *)malloc(strlen(v->teamName) + 1); // allocate memory for the team name
    strcpy(newNode->teamName, v->teamName);

    newNode->val.firstName = (char *)malloc(strlen(v->val.firstName) + 1); // allocate memory for the first name
    strcpy(newNode->val.firstName, v->val.firstName);

    newNode->val.secondName = (char *)malloc(strlen(v->val.secondName) + 1); // allocate memory for the second name
    strcpy(newNode->val.secondName, v->val.secondName);

    newNode->val.points = v->totalPoints;

	newNode->val = v->val;
	newNode->next = *top;
	*top = newNode;
}