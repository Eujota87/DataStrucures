#include <stdio.h>
#include <stdlib.h>
#include "./binarySearchTree.h"

Node *CreateNode(int data) {
    Node *node = malloc(sizeof(Node));
    
    if(node) { //no != NULL 
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    } 

    return node;
}

void InsertOrdered(Node* node, int data) {
    if(!node) return;
    if(node->data == data) return;

    
    if(data < node->data) {
        if(node->left == NULL) node->left = CreateNode(data);
        else InsertOrdered(node->left, data);       
    }
   
    else {
        if(node->right == NULL) node->right = CreateNode(data);
        else InsertOrdered(node->right, data);       
    }

}

void PrintTree_PreOrder(Node* node) {
    if(node) {
        printf("Node data: %i\n", node->data);
        PrintTree_PreOrder(node->left);
        PrintTree_PreOrder(node->right);
    }
}
void PrintTree_Order(Node* node) {
    if(node) {
        PrintTree_Order(node->left);
        printf("Node data: %i\n", node->data);
        PrintTree_Order(node->right);
    }
}
void PrintTree_PostOrder(Node* node) {
    if(node) {
        PrintTree_PostOrder(node->left);
        PrintTree_PostOrder(node->right);
        printf("Node data: %i\n", node->data);
    }
}

int InternalNodes(Node *node) {
    if(!node) return -1;
    if(!node->left && !node->right) return 0;
    return InternalNodes(node->left) + InternalNodes(node->right) + 1;
}

int max(int a, int b) {
    return a > b ? a : b;
}
int TreeHeight(Node *node) {
    if(!node) return -1;
    if(!node->left && !node->right) return 0;
    return max(TreeHeight(node->left), TreeHeight(node->right)) + 1;
}

int ShowPath(Node* node, int data) {
    if(!node) return 0;
    if(node->data == data) {
        printf("(%d)<-", node->data);
        return 1;
    }
    
    int pathFound = 0;
    
    if(data < node->data) pathFound = ShowPath(node->left, data);
    else pathFound = ShowPath(node->right, data);
    
    if(pathFound) {
        printf("(%d)<-", node->data);
        return 1;
    }

    return 0;
}
