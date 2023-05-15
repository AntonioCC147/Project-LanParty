void addAtBeginning(Team **head, char *teamName, int teamMates, float totalPoints, Player value);
void addAtEnd(Team **head, char *teamName, int teamMates, float totalPoints, Player value);

void averagePoints(Team **teamList, int numOfTeams);
Team* lowestPoints(Team **teamList, int numOfTeams);

int findTeamIndex(Team **teamList, int numOfTeams, Team *teamToFind);

void deleteTeam(Team **teamList, int *numOfTeams, int index);
void eliminationTeams(Team **teamList, int *numofTeams, int totalTeamsAfterElimination);

void deleteElement(struct Team **head, char *teamNameDelete);
void deleteList(Team **head);

void displayFileTeamName(char *fileRead, Team *head);