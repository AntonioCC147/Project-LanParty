typedef struct BST{
    Team data;
    struct BST *left, *right;
    int height;
}BST;

BST *newNode(Team data);
BST *insertBST(BST *node, Team key);

int maxValue(int num1, int num2);
int height(BST *node);
int getBalance(BST *node);

BST *leftRotation(BST *x);
BST *rightRotation(BST *y);
BST *LRRotation(BST *Z);
BST *RLRotation(BST *Z);

void transformAVL(BST **AVL, BST *root);
BST* insertAVL(BST* node, Team *key);

void displayTeamsAndPoints(FILE *fileName, BST *root);
void displayTeamsFromLevel(FILE *fileName, BST *root);