#include "list.h"

typedef struct Stack{
    Team val;
    struct Stack *next;
}Stack;

void createStack(Stack **top, Team *v);

int isEmptyStack(Team *top);

void deleteStack(Stack **top);

void displayStack(Stack *top);
void displayMatchesOnFile(char *fileName, char *firstTeamName, char *secondTeamName);
char* returnWinnerTeamName(Stack **top);