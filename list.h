void addAtBeginning(Team **head, int teamMates, char *teamName, Player v);
void addAtEnd(Team **head, int teamMates, char *teamName, Player v);

void averagePoints(Team **teamList, int numOfTeams);
Team* lowestPoints(Team **teamList, int numOfTeams);

int findTeamIndex(Team **teamList, int numOfTeams, Team *teamToFind);
void deleteTeam(Team **teamList, int *numOfTeams, int index);
void eliminationTeams(Team **teamList, int *numofTeams, int totalTeamsAfterElimination);

void deleteElement(struct Team **head, char *teamNameDelete);
void deleteList(Team **head);

void display(Team *head);
void displayFileTeamName(char *fileRead, Team *head);

void resetFile(char *fileName);