#include "main.h"
#include "list.h"
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

    //inchidere fis
    //fclose(fileRead); fclose(tasks); fclose(filePrint);
    }
    
    if(Tasks[2] == 1){
        resetFile(argv[3]);

        // creez coada
        Queue *teamListQueue = createQueue();

        //bag in coada
        for(int i = 0; i < numOfTeams; i++)
            enQueue(teamListQueue, teamList[i]);

        //for de la 0 la numOfTeams in care iau 2 echipe cu dequeue si le bag in lista
        for(int i = 0; i < numOfTeams; i+=2){
            Team *team1 = deQueue(teamListQueue);
            Team *team2 = deQueue(teamListQueue);
            //if(team1->totalPoints > team2->totalPoints) ??
        }
            //if()
        //Stack *firstTeam, *secondTeam;
    }

    return 0;
}