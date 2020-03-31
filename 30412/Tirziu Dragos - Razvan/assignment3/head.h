//
// Created by Dragos on 3/24/2020.
//

#ifndef UNTITLED3_HEAD_H
#define UNTITLED3_HEAD_H

#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    char data;
    struct list *next, *prev;
} NodeL;

NodeL *first, *last;

typedef struct node {
    char id;
    struct node *left, *right;
} NodeT;

void initializeList();

NodeT *createBinaryTree();

void addNode(char data);

NodeL *getListFromTree(NodeT *root);

void traverseList(NodeL *node);

NodeT *getTreeFromList();

void prettyPrint(NodeT *root, int level);
#endif //UNTITLED3_HEAD_H
