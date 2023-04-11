#include "list.h"

typedef struct Stack{
    Team val;
    struct Stack *next;
}Stack;

void createStack(Stack **top, Team *v);

void printStack(Stack *top);


int isEmptyStack(Team *top);

void deleteStack(Stack **top);