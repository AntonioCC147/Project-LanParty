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

    newNode->val.teamName = (char *)malloc(strlen(v->teamName) + 1);
    if (newNode->val.teamName == NULL) {
        free(newNode); // Free previously allocated memory
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(newNode->val.teamName, v->teamName);

    newNode->val.val.firstName = (char *)malloc(strlen(v->val.firstName) + 1);
    if (newNode->val.val.firstName == NULL) {
        free(newNode->val.teamName); // Free previously allocated memory
        free(newNode); // Free previously allocated memory
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(newNode->val.val.firstName, v->val.firstName);

    newNode->val.val.secondName = (char *)malloc(strlen(v->val.secondName) + 1);
    if (newNode->val.val.secondName == NULL) {
        free(newNode->val.val.firstName); // Free previously allocated memory
        free(newNode->val.teamName); // Free previously allocated memory
        free(newNode); // Free previously allocated memory
        printf("Memory allocation failed\n");
        return;
    }
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

void displayMatchesOnFile(char *fileName, char *firstTeamName, char *secondTeamName){
    FILE *file = fopen(fileName, "ab");

    firstTeamName[strlen(firstTeamName)-2] = '\0'; //idk what is this, but it's fix my problem with the unwanted space
    int lenFirstTeamName = strlen(firstTeamName), lenSecondTeamName = strlen(secondTeamName);

    fprintf(file, "%s", firstTeamName);
    for(int i = 0; i < 33-lenFirstTeamName; i++)
        fprintf(file, " ");

    fprintf(file, "-");

    for(int i = 0; i < 35-lenSecondTeamName; i++)
        fprintf(file, " ");
    fprintf(file, "%s", secondTeamName);

    fclose(file);
}

void displayWinnerTeamOnFile(char *fileName, Stack *top, int roundContor) {
    FILE *file = fopen(fileName, "ab");
    fprintf(file, "\n\n\n\n\nWINNERS OF ROUND NO:%d\n", roundContor); 

    while(top != NULL){
        printf("%s - %.2f", top->val.teamName, top->val.totalPoints);
        top=top->next;
    }

    fclose(file);
}

char* returnWinnerTeamName(Stack **top) {
    Stack *newNode = (Stack *)malloc(sizeof(Stack));

    newNode->next = (*top);
    (*top) = newNode;

    char* winnerTeamName = (char*)malloc(sizeof(newNode->val.teamName));
    strcpy(winnerTeamName, newNode->val.teamName);

    return winnerTeamName;
}