#include "main.h"
#include "./headers/queue.h"
#include "./headers/BSTandAVL.h"
#include "./headers/tasksFunctions.h"

#define numberOfTasks 5
#define numberLastEightTeams 8
#define maxCharacter 50

int main(int argc, char *argv[])
{
    FILE *tasks, *fileRead, *filePrint;
    fileDeclaration(argv[1], &tasks, argv[2], &fileRead, argv[3], &filePrint);

    int Tasks[numberOfTasks] = {0};
    fileReadTasks(tasks, numberOfTasks, Tasks);

    int numOfTeams;
    Team **teamList = readfileTeams(fileRead, &numOfTeams);

    if(Tasks[0] == 1)
        Task1(filePrint, teamList, numOfTeams);

    if(Tasks[1] == 1)
        Task2(argv[3], teamList, &numOfTeams);

    Team *lastEightTeam = NULL;
    if(Tasks[2] == 1)
        Task3(argv[3], teamList, &lastEightTeam, numOfTeams, numberLastEightTeams);

    BST *BSTree = NULL, *AVLTree = NULL;
    if(Tasks[3] == 1)
        Task4(argv[3], lastEightTeam, BSTree, &AVLTree);

    if(Tasks[4] == 1)
        Task5(argv[3], AVLTree);

    free(BSTree); free(AVLTree);
    for(int i = 0; i < numOfTeams; i++)
        free(teamList[i]);
    free(teamList);

    return 0;
}