#include <math.h>
#include "main.h"
#include "stack.h"
#include "BSTandAVL.h"

BST *newNode (Team data){ 
    BST *node = (BST*)malloc(sizeof(BST));
    node->data = data;
    node->height = 1;
    node->left = node->right = NULL;
    return node;
}

BST *insertBST(BST *node, Stack *key) {
    // If the (sub)tree is empty, create a new node
    if (node == NULL) return newNode(key->val);
    
    // Compare totalPoints
    if (key->val.totalPoints < node->data.totalPoints) {
        node->left = insertBST(node->left, key); // Insert into left subtree
    } else if (key->val.totalPoints > node->data.totalPoints) {
        node->right = insertBST(node->right, key); // Insert into right subtree
    } else {
        // If totalPoints are equal, compare teamName lexicographically
        int cmp = strcmp(key->val.teamName, node->data.teamName);
        if (cmp > 0) {
            node->right = insertBST(node->right, key); // Insert into right subtree
        } else {
            node->left = insertBST(node->left, key); // Insert into left subtree
        }
    }

    node->height = 1 + max(height(node->left), height(node->right));
    
    return node;
}

void preorder(FILE *fileName, BST *root) {
	if (root){
        preorder(fileName, root->right);
        fprintf(fileName, "%-34s-  %.2f\n", root->data.teamName, root->data.totalPoints);
        preorder(fileName, root->left);
	}
}

//ARBORI

int max(int num1, int num2){
    return (num1 > num2 ) ? num1 : num2;
}

int height(BST *node){
    if (node == NULL)
        return 1;
    return node->height;
}

BST *leftRotation(BST *x){
    BST *y = x->right;
    BST *T2 = y->left;
 
    y->left = x;
    x->right = T2;
 
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
 
    return y;
}

BST *rightRotation(BST *y) {
    BST *x = y->left;
    BST *T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
 
    return x;
}

int getBalance(BST *node){
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

BST *LRRotation(BST *Z){
    Z->left = leftRotation(Z->left);
    return rightRotation(Z);
}

BST *RLRotation(BST *Z){
    Z->right = rightRotation(Z->right);
    return leftRotation(Z);
}

BST* insertAVL(BST* node, Stack *key) {
    /* 1.  Perform the normal BST insertion */
    if (node == NULL) return newNode(key->val);
    
    // Compare totalPoints
    if (key->val.totalPoints < node->data.totalPoints) {
        node->left = insertAVL(node->left, key); // Insert into left subtree
    } else if (key->val.totalPoints > node->data.totalPoints) {
        node->right = insertAVL(node->right, key); // Insert into right subtree
    } else {
        // If totalPoints are equal, compare teamName lexicographically
        int cmp = strcmp(key->val.teamName, node->data.teamName);
        if (cmp > 0) {
            node->right = insertAVL(node->right, key); // Insert into right subtree
        } else if(cmp < 0) {
            node->left = insertAVL(node->left, key); // Insert into left subtree
        }
    }

    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left), height(node->right));

    /* 3. Get the balance factor of this ancestor node to check whether this node became unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1)
        if (key->val.totalPoints < node->left->data.totalPoints)
            return rightRotation(node);
        else if (key->val.totalPoints == node->left->data.totalPoints) {
            // If totalPoints are equal, compare teamName lexicographically
            int cmp = strcmp(key->val.teamName, node->left->data.teamName);
            if (cmp < 0) 
                return rightRotation(node);
        }

    // Right Right Case
    if (balance < -1)
        if (key->val.totalPoints > node->right->data.totalPoints)
            return leftRotation(node);
        else if (key->val.totalPoints == node->right->data.totalPoints) {
            // If totalPoints are equal, compare teamName lexicographically
            int cmp = strcmp(key->val.teamName, node->left->data.teamName);
            if (cmp > 0) 
                return leftRotation(node);
        }

    if(balance > 1 && key->val.totalPoints > node->left->data.totalPoints)
        return LRRotation(node);
    if(balance < -1 && key->val.totalPoints < node->right->data.totalPoints)
        return RLRotation(node);

    /* return the (unchanged) node pointer */
    return node;
}

void preorderAVL(FILE *fileName, BST *root) {
	if (root != NULL){
        preorderAVL(fileName, root->right);
       
        if(root->height == 1)
            fprintf(fileName, "%s\n", root->data.teamName);
        
        preorderAVL(fileName, root->left);
	}
}