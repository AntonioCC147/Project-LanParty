#include <math.h>
#include "../main.h"
#include "../headers/stack.h"
#include "../headers/BSTandAVL.h"

BST *newNode(Team data){
    BST *node = (BST*)malloc(sizeof(BST));
    node->data = data;
    node->height = 1;
    node->left = node->right = NULL;
    return node;
}

BST *insertBST(BST *node, Team key){
    if(node == NULL) return newNode(key);
    
    if(key.totalPoints < node->data.totalPoints)
        node->left = insertBST(node->left, key);
    else if(key.totalPoints > node->data.totalPoints)
        node->right = insertBST(node->right, key);
    else{        
        if(strcmp(key.teamName, node->data.teamName) > 0)
            node->right = insertBST(node->right, key);
        else
            node->left = insertBST(node->left, key);
    }

    node->height = 1 + MAX(height(node->left), height(node->right));
    
    return node;
}

void preorder(FILE *fileName, BST *root){
	if(root){
        preorder(fileName, root->right);
        fprintf(fileName, "%-34s-  %.2f\n", root->data.teamName, root->data.totalPoints);
        preorder(fileName, root->left);
	}
}

int MAX(int num1, int num2){
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
 
    x->height = 1 + MAX(height(x->left), height(x->right));
    y->height = 1 + MAX(height(y->left), height(y->right));
 
    return y;
}

BST *rightRotation(BST *y){
    BST *x = y->left;
    BST *T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    y->height = 1 + MAX(height(y->left), height(y->right));
    x->height = 1 + MAX(height(x->left), height(x->right));
 
    return x;
}

BST *LRRotation(BST *Z){
    Z->left = leftRotation(Z->left);
    return rightRotation(Z);
}

BST *RLRotation(BST *Z){
    Z->right = rightRotation(Z->right);
    return leftRotation(Z);
}

int getBalance(BST *node){
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

void transformAVL(BST **AVL, BST *root){
    if(root){
        transformAVL(AVL, root->right);
        *AVL = insertAVL(*AVL, &(root->data));
        transformAVL(AVL, root->left);
    }
}

BST* insertAVL(BST* node, Team *key) {
    if(node == NULL) return newNode(*key);
    
    if(key->totalPoints < node->data.totalPoints)
        node->left = insertAVL(node->left, key);
    else if(key->totalPoints > node->data.totalPoints)
        node->right = insertAVL(node->right, key);
    else{
        if(strcmp(key->teamName, node->data.teamName) > 0)
            node->right = insertAVL(node->right, key);
        else
            node->left = insertAVL(node->left, key);
    }

    node->height = 1 + MAX(height(node->left), height(node->right));

    int balance = getBalance(node);

    if(balance > 1)
        if(key->totalPoints < node->left->data.totalPoints)
            return rightRotation(node);
        else if(key->totalPoints == node->left->data.totalPoints)
            if (strcmp(key->teamName, node->left->data.teamName) < 0) 
                return rightRotation(node);

    if(balance < -1)
        if(key->totalPoints > node->right->data.totalPoints)
            return leftRotation(node);
        else if(key->totalPoints == node->right->data.totalPoints)
            if(strcmp(key->teamName, node->right->data.teamName) > 0) 
                return leftRotation(node);

    if(balance > 1 && key->totalPoints > node->left->data.totalPoints)
        return LRRotation(node);
    if(balance < -1 && key->totalPoints < node->right->data.totalPoints)
        return RLRotation(node);

    return node;
}

void preorderAVL(FILE *fileName, BST *root){
    if(root != NULL){
        preorderAVL(fileName, root->right);
        if(root->height == 2)
            fprintf(fileName, "%s\n", root->data.teamName);
        preorderAVL(fileName, root->left);
    }
}
