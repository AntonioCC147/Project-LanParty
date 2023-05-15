#include "main.h"
#include "./headers/queue.h"
#include "./headers/BSTandAVL.h"

#define numOfTasks 5
#define lastEightTeams 8
#define maxCaracter 50

int main(int argc, char *argv[])
{
    FILE *tasks = fopen(argv[1], "rt");
    if(tasks == NULL){
        printf("Error! The file cannot be opened."); exit(1);
    }
    int Tasks[numOfTasks] = {0};
    for(int i = 0; i < numOfTasks; i++)
        fscanf(tasks, "%d", &Tasks[i]);

    FILE *fileRead = fopen(argv[2], "rt");
    if(fileRead == NULL){
        printf("Error! The file cannot be opened."); exit(1);
    }

    FILE *filePrint = fopen(argv[3], "wt");
    if(filePrint == NULL){
        printf("Error! The file cannot be opened."); exit(1);
    }

    int numOfTeams, teamMates;
    char teamName[maxCaracter], stringHelp[maxCaracter], spaceDistroyer;

    fscanf(fileRead, "%d", &numOfTeams);
    Team **teamList = (Team **)malloc(numOfTeams * sizeof(Team *));
    if(teamList == NULL){
        printf("Allocation error!"); exit(1);
    }

    // Reading from files
    for(int i = 0; i < numOfTeams; i++){
        teamList[i] = NULL;

        fscanf(fileRead, "%d%c", &teamMates, &spaceDistroyer);
        fgets(teamName, maxCaracter, fileRead);

        Player *p = malloc(teamMates * sizeof(Player));
        if(p == NULL){
            printf("Allocation error!"); exit(1);
        }

        for(int j = 0; j < teamMates; j++){
            fscanf(fileRead, "%s%c", stringHelp, &spaceDistroyer);
            p[j].firstName = malloc(strlen(stringHelp) + 1);
            strcpy(p[j].firstName, stringHelp);

            fscanf(fileRead, "%s%c", stringHelp, &spaceDistroyer);
            p[j].secondName = malloc(strlen(stringHelp) + 1);
            strcpy(p[j].secondName, stringHelp);

            fscanf(fileRead, "%d", &p[j].points);

            addAtBeginning(&(teamList[i]), teamName, teamMates, 0.0, p[j]);
        }

        free(p);
    }

    // Task 1
    if(Tasks[0] == 1){
        for(int i = numOfTeams - 1; i >= 0; i--){
            (teamList[i]->teamName)[strlen(teamList[i]->teamName) - 2] = '\0';
            fprintf(filePrint, "%s\n", teamList[i]->teamName);
        }
        fclose(filePrint);
    }

    // Task 2
    if(Tasks[1] == 1){
        filePrint = fopen(argv[3], "wt");

        averagePoints(teamList, numOfTeams);

        int totalTeamsAfterElimination = 2;
        while(totalTeamsAfterElimination * 2 <= numOfTeams)
            totalTeamsAfterElimination *= 2;

        eliminationTeams(teamList, &numOfTeams, totalTeamsAfterElimination);

        for(int i = numOfTeams - 1; i >= 0; i--)
            fprintf(filePrint, "%s\n", teamList[i]->teamName);

        fclose(filePrint);
    }

    // Task 3
    Team *lastEightTeam = NULL;
    if(Tasks[2] == 1){
        int roundContor = 1;
        
        Queue *teamListQueue = createQueue();
        for(int i = numOfTeams - 1; i >= 0; i--)
            enQueue(teamListQueue, teamList[i]);

        Stack *winnerTeam, *defeatedTeam;
        while(numOfTeams > 1){
            filePrint = fopen(argv[3], "at");
            fprintf(filePrint, "\n--- ROUND NO:%d\n", roundContor);

            for(int i = 0; i < numOfTeams; i += 2){
                Team *firstTeam = deQueue(teamListQueue), *secondTeam = deQueue(teamListQueue);

                if((secondTeam->teamName)[strlen(secondTeam->teamName) - 1] == ' ')
                    (secondTeam->teamName)[strlen(secondTeam->teamName) - 1] = '\0';

                fprintf(filePrint, "%-33s-%33s\n", firstTeam->teamName, secondTeam->teamName);

                if(firstTeam->totalPoints > secondTeam->totalPoints){
                    (firstTeam->totalPoints) = firstTeam->totalPoints + 1.0;
                    createStack(&winnerTeam, firstTeam);
                    createStack(&defeatedTeam, secondTeam);
                }
                else{
                    (secondTeam->totalPoints) = secondTeam->totalPoints + 1.0;
                    createStack(&winnerTeam, secondTeam);
                    createStack(&defeatedTeam, firstTeam);
                }

                free(firstTeam); free(secondTeam);
            }

            free(defeatedTeam);

            fprintf(filePrint, "\nWINNERS OF ROUND NO:%d\n", roundContor);

            numOfTeams = numOfTeams / 2;
            roundContor++;

            int indexWinners = 0;
            Stack *winners = winnerTeam;
            while(indexWinners < numOfTeams){
                fprintf(filePrint, "%-34s-  %.2f\n", winners->val.teamName, winners->val.totalPoints);

                if(numOfTeams == lastEightTeams)
                    addAtBeginning(&lastEightTeam, winners->val.teamName, winners->val.teamMates, winners->val.totalPoints, winners->val.val);

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

    // Task 4
    BST *BSTree = NULL, *AVLTree = NULL;
    if(Tasks[3] == 1){
        filePrint = fopen(argv[3], "at");
        fprintf(filePrint, "\nTOP 8 TEAMS:\n");

        while(lastEightTeam != NULL){
            BSTree = insertBST(BSTree, *lastEightTeam);
            lastEightTeam = lastEightTeam->next;
        }

        displayTeamsAndPoints(filePrint, BSTree);
        transformAVL(&AVLTree, BSTree);
        free(lastEightTeam);

        fclose(filePrint);
    }

    // Task 5
    if(Tasks[4] == 1){
        filePrint = fopen(argv[3], "at");

        fprintf(filePrint, "\nTHE LEVEL 2 TEAMS ARE: \n");
        displayTeamsFromLevel(filePrint, AVLTree);

        fclose(filePrint);
    }

    // Memory free
    free(BSTree); free(AVLTree);

    for(int i = 0; i < numOfTeams; i++)
        free(teamList[i]);
    free(teamList);

    return 0;
}