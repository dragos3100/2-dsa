//
// Created by Dragos on 3/2/2020.
//

#ifndef UNTITLED2_HEAD_H
#define UNTITLED2_HEAD_H

#endif //UNTITLED2_HEAD_H


#include <stdio.h>
#include <stdlib.h>

#define MAX_COMMAND 15
void initializeSll();
void AF(int data);
void AL(int data);
void DF();
void DL();
void DOOM_THE_LIST();
void DE(int data);
void PRINT_ALL ();
void PRINT_F (int data);
int lenght();
void PRINT_L(int data);

typedef struct node {
    int data;
    struct node *next;
} Node;

Node * first, * last;