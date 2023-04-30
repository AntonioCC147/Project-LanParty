#include "list.h"

typedef struct Stack{
    Team val;
    struct Stack *next;
}Stack;

void createStack(Stack **top, Team *v);
void deleteStack(Stack **top);

int isEmptyStack(Team *top);
void displayStack(Stack *top);
