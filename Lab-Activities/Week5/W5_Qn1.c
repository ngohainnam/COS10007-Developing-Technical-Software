/*
Unit Code: COS10007
Unit Name: Developing Techinical Software
Student ID: 103488515
Name: Hai Nam Ngo
Date Created: 3/28/2023
Date Modified: 3/28/2023
Problem: Week 5 Question 1
Problem Description: insert ten letters in the alphabet from A and then reverse and print out both
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    char a;
    struct node *next;
};

typedef struct node Node;
typedef Node *nodePtr;

void printList(nodePtr currentPtr)
{
    while(currentPtr!=NULL)
    {
        printf("%c -> ",currentPtr->a);
        currentPtr=currentPtr->next;
    }
    printf("NULL");
}

nodePtr reverseList(nodePtr currentPtr)
{
    nodePtr previousPtr=NULL, nextPtr;
    while(currentPtr!=NULL)
    {
        nextPtr=currentPtr->next;
        currentPtr->next=previousPtr;
        previousPtr=currentPtr;
        currentPtr=nextPtr;
    }
    return previousPtr;
}

int main()
{
    nodePtr startPtr=NULL, newPtr, currentPtr;
    char x='A';
    for(int i=0;i<10;i++)
    {
        newPtr=malloc(sizeof(Node));
        newPtr->a=x;
        newPtr->next=NULL;
        
        if(startPtr==NULL)
        {
            startPtr=newPtr;
            currentPtr=newPtr;
        }
        else
        {
            currentPtr->next=newPtr;
            currentPtr=newPtr;
        }
        x++;
    }
    currentPtr=startPtr;
    printf("The list is \n");
    printList(currentPtr);
    currentPtr=reverseList(currentPtr);
    printf("\n\nThe list in after reversing the node \n");
    printList(currentPtr);
} 