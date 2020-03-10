//
// Created by Dragos on 3/2/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "head.h"

void initializeSll()
{
    first = NULL;
    last = NULL;
    sentinel =NULL;
}

void AF(int x)
{
    if((first)==NULL) {
        first = (nodeT*)malloc(sizeof(nodeT));
        sentinel=(nodeT*)malloc(sizeof(nodeT));
        (nodeT*)malloc(sizeof(nodeT));
        first->next = last;
        first->prev = NULL;
        first->value = x;
        last = first;
        last->prev = first;
        last->next=NULL;
    }
    else {
        nodeT *newFirst = (nodeT*)malloc(sizeof(nodeT));
        newFirst->value=x;
        newFirst->next=first;
        newFirst->prev=NULL;
        first=newFirst;
    }


}
void AL(int x)
{
    nodeT *newLast = (nodeT*)malloc(sizeof(nodeT));
    newLast->prev = last;
    newLast->value=x;
    newLast->next=NULL;
    last->next = newLast;
    last=newLast;
}
void DF()
{
    if(first==NULL)
    {
        return;
    }
    nodeT *newFirst = first->next;
    free(first);
    first=newFirst;
}
void DL()
{
    if(first==NULL)
    {
        return;
    }
    nodeT *newLast = last;
    last=last->prev;
    last->next=NULL;
    free(newLast);
}
void DOOM_THE_LIST()
{
    nodeT * currentElement = first;
    while(currentElement != NULL) {
        currentElement = first->next;
        free(first);
        first = currentElement;
    }
}
void DE(int x)
{
    nodeT * currentElement = first;
    nodeT * previousElement= first;
    int foundElement=0;
    while(currentElement != NULL && foundElement==0) {
        if(currentElement->value == x) {
            foundElement=1;
            if(currentElement == first) {
                first = first->next;
            }
            else if(currentElement == last) {
                last = previousElement;
                last->next = NULL;
            }
            else {
                previousElement->next = currentElement->next;
            }
            previousElement = currentElement;
            currentElement = currentElement->next;
            free(previousElement);
            previousElement = currentElement;
        }
        else {
            previousElement = currentElement;
            currentElement = currentElement->next;
        }

    }

}
void PRINT_ALL ()
{
    FILE *outputFile = fopen("..\\output.dat", "a");
    if(first == NULL) {
        printf("List is empty!\n");
    }
    else {
        nodeT * currentElement = first;
        while(currentElement != NULL) {
            fprintf(outputFile, "%d ", currentElement->value);
            currentElement = currentElement->next;
        }
        fprintf(outputFile, "\n");
    }
    fclose(outputFile);

}
void PRINT_F (int x)
{
    FILE *outputFile = fopen("..\\output.dat", "a");
    nodeT *currentNode = first;
    while (x>0 || currentNode == NULL) {
        fprintf(outputFile, "%d ", currentNode->value);
        --x;
    }
    fprintf(outputFile, "\n");
    fclose(outputFile);
}


void PRINT_L(int x)
{
    FILE *outputFile = fopen("..\\output.dat", "a");
    nodeT *currentNode = last;
    for (int i=0;i<x;++i) {
        fprintf(outputFile, "%d ", currentNode->value);
        currentNode = currentNode->prev;
    }
}