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
}

void AF(int data)
{
    if(first == NULL)
    {
        first = (Node*)malloc(sizeof(Node));
        first->next = last;
        first->data = data;
        last = first;
    }
    else
    {
        Node * temp=(Node*)malloc(sizeof(Node));
        temp->data=data;
        temp->next=first;
        first=temp;
    }

}
void AL(int data)
{
    if(first == NULL)
    {
        first = (Node*)malloc(sizeof(Node));
        first->next = last;
        first->data = data;
        last = first;
    }
    else
    {
        Node * temp=(Node*)malloc(sizeof(Node));
        temp->next=NULL;
        temp->data=data;
        last->next=temp;
        last=temp;
    }
}
void DF()
{
    if(first==NULL)
    {
        return;
    }
    Node *temp=first;
    first=first->next;
    free(temp);
}
void DL()
{
    if(first==NULL)
    {
        return;
    }
    if(first==last)
    {
            free(first);
            first=NULL;
            last=NULL;
    }
    else
    {
        Node *temp=first;
        while(temp->next!=last)
        {
            temp=temp->next;
        }
        free(last);
        temp->next=NULL;
        last=temp;

    }
}
void DOOM_THE_LIST()
{
    Node *temp=first;
    while(temp!=NULL)
    {
        first=first->next;
        free(temp);
        temp=first;
    }
}
void DE(int data)
{
    Node * currentElement = first;
    Node * previousElement= first;
    while(currentElement != NULL)
    {
        if(currentElement->data == data)
        {
            if(currentElement == first)
            {
                first = first->next;
            }
            else if(currentElement == last)
            {
                last = previousElement;
                last->next = NULL;
            }
            else
            {
                previousElement->next = currentElement->next;
            }
            previousElement = currentElement;
            currentElement = currentElement->next;
            free(previousElement);
            previousElement = currentElement;
        }
        else
        {
            previousElement = currentElement;
            currentElement = currentElement->next;
        }

    }
}
void PRINT_ALL ()
{
    if(first == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        Node * temp = first;
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }

}
void PRINT_F (int data)
{
    int c=0;
    if(first == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        Node * temp = first;
        while((temp != NULL)&&(c<data))
        {
            printf("%d ", temp->data);
            temp = temp->next;
            c++;
        }
        printf("\n");
    }
}
int lenght()
{
    int count=0;
    Node *temp;
    temp=first;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

void PRINT_L(int data)
{
    int c=lenght(),k=0;
    c=c-data;
    if(first == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        Node * temp = first;
        while((temp != NULL)&&(c<k))
        {
            printf("%d ", temp->data);
            temp = temp->next;
            k++;
        }
        printf("\n");
    }
}