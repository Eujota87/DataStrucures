#include <stdio.h>
#include "./binarySearchTree.h"

/*

Árvore de Busca Binária:

-Árvores de Busca Binária possuem a propriedade em que
os filhos a esquerda de um nó são menores que ele, e
os filhos a direita desse nó são maiores que ele



- Construção
- Inserção
- Busca
- Remoção

- Percursos:
    - Pré-ordem
    - Em ordem
    - Pós ordem

*/

int main() {

    Node* tree = CreateNode(4);
    InsertOrdered(tree, 2);
    InsertOrdered(tree, 1);
    InsertOrdered(tree, 3);
    InsertOrdered(tree, 6);
    InsertOrdered(tree, 5);
    InsertOrdered(tree, 7);
    PrintTree_PreOrder(tree);

    printf("Number of internal nodes: %i\n", InternalNodes(tree));
    printf("Tree height: %i\n", TreeHeight(tree));

    printf("Path to number %i:\n", 5);
    ShowPath(tree, 5);
    printf("\n");

}