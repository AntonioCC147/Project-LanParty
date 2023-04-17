#include "main.h"
#include "stack.h"
#include "BSTandAVL.h"

BST *newNode (Team data){ 
    BST *node = (BST*)malloc(sizeof(BST));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

BST *insert (BST *node, Stack *key){
    //Team *aux;
    // daca ( sub) arborele este gol , creaza nod
    if(node == NULL) return newNode(key->val);
    // altfel , coboara la stanga sau dreapta
    if(key->val.totalPoints < node->data.totalPoints)
    node->left = insert (node->left, key);
    else if(key->val.totalPoints > node->data.totalPoints)
    node->right = insert (node->right, key);
    else if(key->val.totalPoints == node->data.totalPoints)
        if(strcmp(key->val.teamName, node->data.teamName) > 0){
            
        }
    // ! pointerul node se intoarce nemodificat pe acest return
    //else 
    //cazul in care sunt punctaje egale
    


    return node;
}

void preorder(char *fileName, BST *root) {
    FILE *file = fopen(fileName, "at");

	if (root){
        preorder(fileName, root->right);
        fprintf(file, "%-34s-  %.2f\n", root->data.teamName, root->data.totalPoints);
        preorder(fileName, root->left);
		
	}

    fclose(file);
}