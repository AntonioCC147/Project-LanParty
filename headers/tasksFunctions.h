void openFileError();
void allocationError();

void fileDeclaration(char *file1, FILE **fileName1, char *file2, FILE **fileName2, char *file3, FILE **fileName3);
void fileReadTasks(FILE *tasks, int numberOfTasks, int Tasks[]);
Team** readfileTeams(FILE* fileRead, int* numOfTeams);

int powerOfTwo(int *totalTeamsAfterElimination, int numOfTeams);
void winnerAndDefeated(FILE *filePrint, int numOfTeams, Queue *teamListQueue, Stack **winnerTeam, Stack **defeatedTeam);

void Task1(FILE *filePrint, Team** teamList, int numOfTeams);
void Task2(char *argv, Team** teamList, int* numOfTeams);
void Task3(char* argv, Team** teamList, Team** lastEightTeam, int numOfTeams, int numberLastEightTeams);
void Task4(char *filename, Team* lastEightTeam, BST* BSTree, BST** AVLTree);
void Task5(char *argv, BST* AVLTree);