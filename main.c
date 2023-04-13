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

    FILE *filePrint = fopen(argv[3], "wb");
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

        //fclose(filePrint); //de sters daaca nu se modifica ceva
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
        filePrint = fopen(argv[3], "ab");

        Queue *teamListQueue = createQueue();
        int roundContor = 1;

        for(int i = numOfTeams - 1; i >= 0; i--)
            enQueue(teamListQueue, teamList[i]);

        Stack *winnerTeam, *defeatedTeam;
        while(numOfTeams > 8){
            fprintf(filePrint, "\n--- ROUND NO:%d\n", roundContor); fclose(filePrint);

            
            for(int i = 0; i < numOfTeams; i+=2){
                filePrint = fopen(argv[3], "ab");
                Team *firstTeam = deQueue(teamListQueue);
                Team *secondTeam = deQueue(teamListQueue);

                //displayMatchesOnFile(argv[3], firstTeam->teamName, secondTeam->teamName); foloseste asta sau aia de mai jos

                firstTeam->teamName[strlen(firstTeam->teamName)-2] = '\0'; //idk what is this, but it's fix my problem with the unwanted space
                int lenFirstTeamName = strlen(firstTeam->teamName), lenSecondTeamName = strlen(secondTeam->teamName);

                fprintf(filePrint, "%s", firstTeam->teamName);
                for(int j = 0; j < 33-lenFirstTeamName; j++)
                    fprintf(filePrint, " ");

                fprintf(filePrint, "-");

                for(int j = 0; j < 35-lenSecondTeamName; j++)
                    fprintf(filePrint, " ");
                fprintf(filePrint, "%s", secondTeam->teamName);

                fclose(filePrint);

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

            filePrint = fopen(argv[3], "ab");
            fprintf(filePrint, "\nWINNERS OF ROUND NO:%d\n", roundContor); 

            //scrie aici afisarea, fa totul manual, fara functii

            fclose(filePrint);

            enQueueWinnerTeam(teamListQueue, winnerTeam);
            deleteStack(&defeatedTeam); deleteStack(&winnerTeam);

            numOfTeams = numOfTeams / 2; roundContor++;
        }
    }

    //eliberare de memorie
    /*
    for(int i = 0; i < numOfTeams; i++)
        free(teamList[i]);
    free(teamList);
    */

    return 0;
}