#include "../main.h"
#include "../headers/queue.h"
#include "../headers/BSTandAVL.h"

#define maxCharacter 50

void openFileError(){
    printf("Error! The file cannot be opened!"); exit(1);
}

void allocationError(){
    printf("Memory allocation error!"); exit(1);
}

void fileDeclaration(char *file1, FILE **fileName1, char *file2, FILE **fileName2, char *file3, FILE **fileName3) {
    *fileName1 = fopen(file1, "rt");
    if(*fileName1 == NULL)
        openFileError();

    *fileName2 = fopen(file2, "rt");
    if(*fileName2 == NULL)
        openFileError();

    *fileName3 = fopen(file3, "wt");
    if(*fileName3 == NULL)
        openFileError();
}

void fileReadTasks(FILE *tasks, int numberOfTasks, int Tasks[]){
    for(int i = 0; i < numberOfTasks; i++)
        fscanf(tasks, "%d", &Tasks[i]);
}

Team** readfileTeams(FILE *fileRead, int *numOfTeams){
    int numberOfTeamMates; char teamName[maxCharacter], stringHelp[maxCharacter], spaceDistroyer;

    fscanf(fileRead, "%d", numOfTeams);
    Team **teamList = (Team**)malloc((*numOfTeams) * sizeof(Team*));
    if(teamList == NULL)
        allocationError();

    for(int i = 0; i < (*numOfTeams); i++){
        teamList[i] = NULL;

        fscanf(fileRead, "%d%c", &numberOfTeamMates, &spaceDistroyer);
        fgets(teamName, maxCharacter, fileRead);

        Player *player = malloc(numberOfTeamMates * sizeof(Player));
        if(player == NULL)
            allocationError();

        for(int j = 0; j < numberOfTeamMates; j++){
            fscanf(fileRead, "%s%c", stringHelp, &spaceDistroyer);
            player[j].firstName = malloc(strlen(stringHelp) + 1);
            if(player[j].firstName == NULL)
                allocationError();

            strcpy(player[j].firstName, stringHelp);

            fscanf(fileRead, "%s%c", stringHelp, &spaceDistroyer);
            player[j].secondName = malloc(strlen(stringHelp) + 1);
            if(player[j].secondName == NULL)
                allocationError();
   
            strcpy(player[j].secondName, stringHelp);

            fscanf(fileRead, "%d", &player[j].points);

            addAtBeginning(&(teamList[i]), teamName, numberOfTeamMates, 0.0, player[j]);
        }

        free(player);
    }

    return teamList;
}

int powerOfTwo(int *totalTeamsAfterElimination, int numOfTeams){
    while(*totalTeamsAfterElimination * 2 <= numOfTeams)
         (*totalTeamsAfterElimination) *= 2;
    return  *totalTeamsAfterElimination;
}

void winnerAndDefeated(FILE *filePrint, int numOfTeams, Queue *teamListQueue, Stack **winnerTeam, Stack **defeatedTeam){
    for(int i = 0; i < numOfTeams; i += 2){
        Team *firstTeam = deQueue(teamListQueue), *secondTeam = deQueue(teamListQueue);

        if((secondTeam->teamName)[strlen(secondTeam->teamName) - 1] == ' ')
            (secondTeam->teamName)[strlen(secondTeam->teamName) - 1] = '\0';

        fprintf(filePrint, "%-33s-%33s\n", firstTeam->teamName, secondTeam->teamName);

        if(firstTeam->totalPoints > secondTeam->totalPoints){
            firstTeam->totalPoints += 1;
            createStack(winnerTeam, firstTeam);
            createStack(defeatedTeam, secondTeam);
        }
        else{
            secondTeam->totalPoints += 1;
            createStack(winnerTeam, secondTeam);
            createStack(defeatedTeam, firstTeam);
        }

        free(firstTeam); free(secondTeam);
    }

    free(*defeatedTeam);
}

void Task1(FILE *filePrint, Team **teamList, int numOfTeams){
    for(int i = numOfTeams - 1; i >= 0; i--){
        (teamList[i]->teamName)[strlen(teamList[i]->teamName) - 2] = '\0';
        fprintf(filePrint, "%s\n", teamList[i]->teamName);
    }

    fclose(filePrint);
}

void Task2(char *argv, Team **teamList, int *numOfTeams){
    FILE* filePrint = fopen(argv, "wt");
    if(filePrint == NULL)
        openFileError();

    averagePoints(teamList, *numOfTeams);

    int totalTeamsAfterElimination = 2;
    powerOfTwo(&totalTeamsAfterElimination, *numOfTeams);

    eliminationTeams(teamList, numOfTeams, totalTeamsAfterElimination);

    for(int i = *numOfTeams - 1; i >= 0; i--)
        fprintf(filePrint, "%s\n", teamList[i]->teamName);

    fclose(filePrint);
}

void Task3(char *argv, Team **teamList, Team **lastEightTeam, int numOfTeams, int numberLastEightTeams){
    int roundContor = 1;

    Queue *teamListQueue = createQueue();
    for (int i = numOfTeams - 1; i >= 0; i--)
        enQueue(teamListQueue, teamList[i]);

    Stack *winnerTeam = NULL, *defeatedTeam = NULL;

    while(numOfTeams > 1){
        FILE* filePrint = fopen(argv, "at");
        if(filePrint == NULL)
            openFileError();

        fprintf(filePrint, "\n--- ROUND NO:%d\n", roundContor);

        winnerAndDefeated(filePrint, numOfTeams, teamListQueue, &winnerTeam, &defeatedTeam);

        fprintf(filePrint, "\nWINNERS OF ROUND NO:%d\n", roundContor);

        numOfTeams = numOfTeams / 2; roundContor++;

        int indexWinners = 0;
        Stack *winners = winnerTeam;
        while(indexWinners < numOfTeams){
            fprintf(filePrint, "%-34s-  %.2f\n", winners->val.teamName, winners->val.totalPoints);

            if(numOfTeams == numberLastEightTeams)
                addAtBeginning(lastEightTeam, winners->val.teamName, winners->val.teamMates, winners->val.totalPoints, winners->val.val);

            winners = winners->next;
            indexWinners++;
        }

        fclose(filePrint);

        free(teamListQueue);
        teamListQueue = createQueue();

        for(int j = numOfTeams - 1; j >= 0; j--){
            enQueueStack(teamListQueue, winnerTeam);
            winnerTeam = winnerTeam->next;
        }
    }
}

void Task4(char *argv, Team *lastEightTeam, BST *BSTree, BST **AVLTree){
    FILE *filePrint = fopen(argv, "at");
    if(filePrint == NULL)
        openFileError();

    fprintf(filePrint, "\nTOP 8 TEAMS:\n");

    while(lastEightTeam != NULL){
        BSTree = insertBST(BSTree, *lastEightTeam);
        lastEightTeam = lastEightTeam->next;
    }

    displayTeamsAndPoints(filePrint, BSTree);
    transformAVL(AVLTree, BSTree);
    free(lastEightTeam);

    fclose(filePrint);
}

void Task5(char *argv, BST *AVLTree){
    FILE* filePrint = fopen(argv, "at");
    if(filePrint == NULL)
        openFileError();

    fprintf(filePrint, "\nTHE LEVEL 2 TEAMS ARE: \n");
    displayTeamsFromLevel(filePrint, AVLTree);

    fclose(filePrint);
}