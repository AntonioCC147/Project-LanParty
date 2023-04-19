#include <math.h>
#include "main.h"
#include "stack.h"
#include "BSTandAVL.h"

BST *newNode (Team data){ 
    BST *node = (BST*)malloc(sizeof(BST));
    node->data = data;
    node->height = 0;
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

int height(BST *node) {
    if (node == NULL) return -1;
    return node->height;
}

BST *rightRotation(BST *z) {
    BST *y = z->left;
    BST *T3 = y->right;    
    y->right = z;
    z->left = T3;
    z->height = 1 + max(height(z->left), height(z->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y; 
} 

BST *leftRotation(BST *z) {
    BST *y = z->right;
    BST *T2 = y->left;
    y->left = z;
    z->right = T2;
    z->height = 1 + max(height(z->left), height(z->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}

BST *LRRotation(BST *Z){
    Z->left = leftRotation(Z->left);
    return rightRotation(Z);
}

BST *RLRotation(BST *Z){
    Z->right = rightRotation(Z->right);
    return leftRotation(Z);
}

BST* search(BST* root, BST key) {
	if (root->data.totalPoints == key.data.totalPoints)
		return root;
	if (root->data.totalPoints < key.data.totalPoints)  
		return search(root->right, key);
	return search(root->left, key);

	return 0;
}

BST *insertAVL(BST *node, Stack *key) {
    // If the (sub)tree is empty, create a new node
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
        } else {
            node->left = insertAVL(node->left, key); // Insert into left subtree
        }
    }

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    node->height = 1 + max(leftHeight, rightHeight);

    int k = (leftHeight - rightHeight);

    if(k > 1 && key->val.totalPoints < node->left->data.totalPoints)
        return rightRotation(node);
    
    if(k < -1 && key->val.totalPoints > node->right->data.totalPoints)
        return leftRotation(node);

    if(k > 1 && key->val.totalPoints > node->left->data.totalPoints)
        return RLRotation(node);

    if(k < -1 && key->val.totalPoints < node->right->data.totalPoints)
        return LRRotation(node); 
    
    return node;
}

void preorderAVL(FILE *fileName, BST *root) {
	if (root){
        if(root->height == 2)
            fprintf(fileName, "%-34s-  %.2f - %d\n", root->data.teamName, root->data.totalPoints, root->height);
        preorderAVL(fileName, root->left);
        preorderAVL(fileName, root->right);
	}
}