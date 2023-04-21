typedef struct BST{
    Team data;
    struct BST *left, *right;
    int height;
}BST;

BST *newNode(Team data);

BST *insertBST(BST *node, Stack *key);

void preorder(FILE *fileName, BST *root);

//

int max(int num1, int num2);
int height(BST *node);

BST *leftRotation(BST *x);
BST *rightRotation(BST *y);
int getBalance(BST *node);

BST *LRRotation(BST *Z);
BST *RLRotation(BST *Z);

BST *insertAVL(BST* node, Stack *key);

void preorderAVL(FILE *fileName, BST *root);