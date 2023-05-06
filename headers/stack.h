#include "list.h"

typedef struct Stack{
    Team val;
    struct Stack *next;
}Stack;

int isEmptyStack(Team *top);
void createStack(Stack **top, Team *v);
void deleteStack(Stack **top);