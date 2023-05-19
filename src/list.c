#include "../main.h"
#include "../headers/list.h"

void addAtBeginning(Team **head, char *teamName, int teamMates, float totalPoints, Player value){
    Team *newTeam = (Team *)malloc(sizeof(Team));

    newTeam->teamMates = teamMates;
    newTeam->totalPoints = totalPoints;
    newTeam->val.points = value.points;

    newTeam->teamName = (char *)malloc(strlen(teamName) +1);
    strcpy(newTeam->teamName, teamName);

    newTeam->val.firstName = (char *)malloc(strlen(value.firstName) + 1);
    strcpy(newTeam->val.firstName, value.firstName);

    newTeam->val.secondName = (char *)malloc(strlen(value.secondName) + 1);
    strcpy(newTeam->val.secondName, value.secondName);

    newTeam->next = *head;
    *head = newTeam;
}

void addAtEnd(Team **head, char *teamName, int teamMates, float totalPoints, Player value){
    Team *aux = *head, *newTeam = (Team *)malloc(sizeof(Team));

    newTeam->teamMates = teamMates;
    newTeam->totalPoints = totalPoints;
    newTeam->val.points = value.points;

    newTeam->teamName = (char *)malloc(strlen(teamName) + 1);
    strcpy(newTeam->teamName, teamName);

    newTeam->val.firstName = (char *)malloc(strlen(value.firstName) + 1);
    strcpy(newTeam->val.firstName, value.firstName);

    newTeam->val.secondName = (char *)malloc(strlen(value.secondName) + 1);
    strcpy(newTeam->val.secondName, value.secondName);

    newTeam->next = NULL;

    if(*head == NULL)
        addAtBeginning(head, teamName, teamMates, totalPoints, value);
    else{
        while(aux->next != NULL)
            aux = aux->next;
        aux->next = newTeam;
    }
}

void averagePoints(Team **teamList, int numOfTeams){
    for(int i = 0; i < numOfTeams; i++){
        Team *current = teamList[i];
        float sumOfPoints = 0.0;

        while(current != NULL){
            sumOfPoints += current->val.points;
            current = current->next;
        }
        
        teamList[i]->totalPoints = (sumOfPoints / teamList[i]->teamMates);
    }
}

Team* lowestPoints(Team **teamList, int numOfTeams){
    int index = 0; float minimum = teamList[0]->totalPoints;

    for(int i = 1; i < numOfTeams; i++)
        if(teamList[i]->totalPoints <= minimum){
            minimum = teamList[i]->totalPoints;
            index = i;
        }

    return teamList[index];
}

int findTeamIndex(Team **teamList, int numOfTeams, Team *teamToFind){
    for(int i = 0; i < numOfTeams; i++)
        if(teamList[i] == teamToFind) 
            return i;
}

void deleteTeam(Team **teamList, int *numOfTeams, int index){
    Team *teamToDelete = teamList[index];

    if(index > 0)
        teamList[index-1]->next = teamToDelete->next;

    for(int i = index; i < *numOfTeams-1; i++)
        teamList[i] = teamList[i+1];

    free(teamToDelete->teamName); free(teamToDelete);

    (*numOfTeams)--;
}

void eliminationTeams(Team **teamList, int *numOfTeams, int totalTeamsAfterElimination){
    while(*numOfTeams > totalTeamsAfterElimination){
        Team *teamToDelete = lowestPoints(teamList, *numOfTeams);

        int index = findTeamIndex(teamList, *numOfTeams, teamToDelete);
        
        deleteTeam(teamList, numOfTeams, index);
    }
}

void deleteElement(Team **head, char *teamNameDelete){
    Team *headcopy = *head;
    if(strcmp(headcopy->teamName, teamNameDelete) == 0){
        *head = (*head)->next;
        free(headcopy);
    }

    Team *prev = *head;
    while(headcopy != NULL){
        if(strcmp(headcopy->teamName, teamNameDelete) == 0){
            prev = headcopy;
            headcopy = headcopy->next;
        }
        else{
            prev->next = headcopy->next;
            free(headcopy);
        }
    }
}

void deleteList(Team **head){
    Team *headcopy;

    while(*head != NULL){
        headcopy = (*head)->next;
        free(*head);
        *head = headcopy;
    }

    *head = NULL;
}

void displayFileTeamName(char *fileName, Team *head){
    FILE *file = fopen(fileName, "ab");

    fprintf(file, "%s", head->teamName);

    fclose(file);
}