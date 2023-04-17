typedef struct BST{
    Team data;
    struct BST *left, *right;
}BST;

BST *newNode(Team data);

BST *insert (BST *node, Stack *key);

void preorder(char *fileName, BST *root);