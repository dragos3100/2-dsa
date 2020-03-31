#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main() {
    initializeList();
    NodeT *root = createBinaryTree();
    NodeL *firstFromList = getListFromTree(root);
    traverseList(firstFromList);
    root = getTreeFromList();
    prettyPrint(root, 0);
    return 0;
}