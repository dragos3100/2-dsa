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
void AF(int x);
void AL(int x);
void DF();
void DL();
void DOOM_THE_LIST();
void DE(int x);
void PRINT_ALL ();
void PRINT_F (int x);
int lenght();
void PRINT_L(int x);

FILE *input, *output;


typedef struct nodetype {
    int value;
    struct nodetype *next;
    struct nodetype *prev;
} nodeT;
nodeT *first, *last, *sentinel;