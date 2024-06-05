#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

typedef struct node Node;

struct node {
    int data;
    Node *left;
    Node *right
};

Node *CreateNode(int data);

void InsertOrdered(Node* node, int data);

void PrintTree_PreOrder(Node* node);
void PrintTree_Order(Node* node);
void PrintTree_PostOrder(Node* node);

int InternalNodes(Node* node);
int TreeHeight(Node* node);
int ShowPath(Node* node, int data);

#endif