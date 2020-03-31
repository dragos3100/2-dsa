//
// Created by Dragos on 3/24/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

void initializeList() {
    first = NULL;
    last = NULL;
}

NodeT *createBinaryTree() {
    char *c = malloc(sizeof(char));
    scanf("%s", c);
    if (strcmp(c, "*") == 0) {
        return NULL;
    }
    NodeT *p = (NodeT *) malloc(sizeof(NodeT));
    p->id = c[0];
    p->left = createBinaryTree();
    p->right = createBinaryTree();
    return p;
}

void addNode(char data) {
    if (last == NULL) {
        last = (NodeL *) malloc(sizeof(NodeL));
        last->data = data;
        last->next = NULL;
        last->prev = NULL;
        first = last;
    } else {
        NodeL *newElement = (NodeL *) malloc(sizeof(NodeL));
        newElement->data = data;
        newElement->next = NULL;
        newElement->prev = last;
        last->next = newElement;
        last = newElement;
    }
}

NodeL *getListFromTree(NodeT *root) {
    if (root != NULL) {
        addNode(root->id);
        getListFromTree(root->left);
        getListFromTree(root->right);
    } else {
        addNode('*');
    }
    return first;
}

void traverseList(NodeL *curr) {
    NodeL *current = curr;
    if (first == NULL) {
        printf("Empty list\n");
    } else {
        while (current != NULL) {
            printf("%c", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

NodeT *getTreeFromList() {
    char aux;
    if (first != NULL) {
        aux = first->data;
        first = first->next;
        if (aux == '*') {
            return NULL;
        } else {
            NodeT *root = (NodeT *) malloc(sizeof(NodeT));
            root->id = aux;
            root->left = getTreeFromList();
            root->right = getTreeFromList();
            return root;
        }
    }
    return NULL;
}

void prettyPrint(NodeT *root, int level) {
    if (root != NULL) {
        for (int i = 0; i < level; i++) {
            printf(" ");
        }
        printf("%c", root->id);
        prettyPrint(root->left, level + 1);
        prettyPrint(root->right, level + 1);
    }
}