#include <math.h>
#include "main.h"
#include "stack.h"
#include "BSTandAVL.h"

BST *newNode (Team data){ 
    BST *node = (BST*)malloc(sizeof(BST));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

BST *insert(BST *node, Stack *key) {
    // If the (sub)tree is empty, create a new node
    if (node == NULL) return newNode(key->val);
    
    // Compare totalPoints
    if (key->val.totalPoints < node->data.totalPoints) {
        node->left = insert(node->left, key); // Insert into left subtree
    } else if (key->val.totalPoints > node->data.totalPoints) {
        node->right = insert(node->right, key); // Insert into right subtree
    } else {
        // If totalPoints are equal, compare teamName lexicographically
        int cmp = strcmp(key->val.teamName, node->data.teamName);
        if (cmp > 0) {
            node->right = insert(node->right, key); // Insert into right subtree
        } else {
            node->left = insert(node->left, key); // Insert into left subtree
        }
    }
    
    return node;
}

void preorder(FILE *fileName, BST *root) {
	if (root){
        //preorder(fileName, root->right);
        preorder(fileName, root->right);
        fprintf(fileName, "%-34s-  %.2f\n", root->data.teamName, root->data.totalPoints);
        preorder(fileName, root->left);
	}
}