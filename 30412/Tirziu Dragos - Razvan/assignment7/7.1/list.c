#include "list.h"
#include "io.h"

nodeT * createNode(char * content)
{
    nodeT * n = (nodeT*) malloc(sizeof(nodeT));
    n->content = (char*) malloc(sizeof(char) * MAX_STRING_LENGTH);
    strcpy(n->content, content);
    n->next = NULL;
    return n;
}

void addToList(listT *l, char * content)
{   nodeT *newNode=createNode(content);
    if(l->head==NULL){
        l->head=newNode;
        l->tail=newNode;
    }
    else {
        l->tail->next = newNode;
        l->tail = newNode;
    }
}

void initList(listT *l){
    l->head=l->tail=NULL;
}