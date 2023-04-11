#include "main.h"
#include "queue.h"

int main(int argc, char *argv[])
{
    //definesc fisiere
    FILE *tasks = fopen(argv[1], "rb");
    if(tasks == NULL){
        printf("Error! The file cannot be opened."); exit(1);
    }
    int Tasks[5] = {0};
    for(int i = 0; i < 5; i++)
        fscanf(tasks, "%d", &Tasks[i]);

    FILE *fileRead = fopen(argv[2], "rb");
    if(fileRead == NULL){
        printf("Error! The file cannot be opened."); exit(1);
    }

    FILE *filePrint = fopen(argv[3], "ab");
    if(filePrint == NULL){
        printf("Error! The file cannot be opened."); exit(1);
    }

    //var utile
    int numOfTeams, teamMates;
    char teamName[50], stringHelp[50], spaceDistroyer;

    fscanf(fileRead, "%d", &numOfTeams);
    Team** teamList = (Team**)malloc(numOfTeams * sizeof(Team*));
    if(teamList == NULL){
        printf("Allocation error!"); exit(1);
    }

    //citire task1
    for(int i = 0; i < numOfTeams; i++){

        teamList[i] = 0;
        fscanf(fileRead, "%d%c", &teamMates, &spaceDistroyer); fgets(teamName, 50, fileRead);

        Player *p = malloc(teamMates * sizeof(Player));
        if(p == NULL){
            printf("Allocation error!"); exit(1);
        }

        for(int j = 0; j < teamMates; j++){

            fscanf(fileRead, "%s", stringHelp);
            p[j].firstName = malloc(strlen(stringHelp) + 1); // allocate memory for the first name
            strcpy(p[j].firstName, stringHelp);

            fscanf(fileRead, "%s", stringHelp);
            p[j].secondName = malloc(strlen(stringHelp) + 1); // allocate memory for the second name
            strcpy(p[j].secondName, stringHelp);

            fscanf(fileRead, "%d", &p[j].points);

            addAtBeginning(&(teamList[i]), teamMates, teamName, p[j]);
    
        }

        free(p);

    }

    if(Tasks[0] == 1){
        //afisare task1
        for(int i = numOfTeams - 1; i >= 0; i--)
            displayFileTeamName(argv[3], teamList[i]);

        fclose(filePrint);
    }

    if(Tasks[1] == 1){
        resetFile(argv[3]);

        //media task2
        averagePoints(teamList, numOfTeams);

        //eliminare task2
        int totalTeamsAfterElimination = 2;
        while(totalTeamsAfterElimination < numOfTeams)
            totalTeamsAfterElimination *= 2;
        totalTeamsAfterElimination /= 2;

        eliminationTeams(teamList, &numOfTeams, totalTeamsAfterElimination);

        for(int i = numOfTeams - 1; i >= 0; i--)
            displayFileTeamName(argv[3], teamList[i]);
    }
    
    if(Tasks[2] == 1){
        //redeschid fisierul
        filePrint = fopen(argv[3], "ab");

        // creez coada
        Queue *teamListQueue = createQueue();

        //bag in coada
        for(int i = 0; i < numOfTeams; i++)
            enQueue(teamListQueue, teamList[i]);

        //creez winer si loser
        Stack *winnerTeam, *defeatedTeam;

        //while(numOfTeams > 8){
            fprintf(filePrint, "\n--- ROUND NO:%d\n", numOfTeams);

            //for de la 0 la numOfTeams in care iau 2 echipe cu dequeue si le bag in lista
            for(int i = 0; i < numOfTeams; i+=2){
                Team *firstTeam = deQueue(teamListQueue);
                Team *secondTeam = deQueue(teamListQueue);

                if(firstTeam->totalPoints >= secondTeam->totalPoints){
                    (firstTeam->totalPoints)++;
                    createStack(&winnerTeam, firstTeam);
                    createStack(&defeatedTeam, secondTeam);
                }
                else{
                    (secondTeam->totalPoints)++;
                    createStack(&winnerTeam, secondTeam);
                    createStack(&defeatedTeam, firstTeam);
                }
            }
                
            //sterg loserii
            //deleteStack(&defeatedTeam);
            //deleteQueue(teamListQueue);
            //enQueueWinnerTeam(teamListQueue, winnerTeam);

            numOfTeams = numOfTeams / 2;
        }

        //printStack(winnerTeam);

        /*
        fprintf(file, "\n--- ROUND NO:%d\n", roundNumber);
        fprintf(file, "%-33s-%33s\n", match->firstTeam->name, match->secondTeam->name);
        */
    //}

    //eliberare de memorie
    /*
    for(int i = 0; i < numOfTeams; i++)
        free(teamList[i]);
    free(teamList);
    */

    return 0;
}