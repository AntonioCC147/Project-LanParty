#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_MIN -2147483648
#define finalTeams 8

typedef struct Player{
    char *firstName;
    char *secondName;
    int points;
}Player;

typedef struct Team{
    int teamMates;
    char *teamName;
    float totalPoints;
    
    Player val;
    struct Team *next;
}Team;