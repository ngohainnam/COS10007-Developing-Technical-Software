/*
Unit Code: COS10007
Unit Name: Developing Techinical Software
Student ID: 103488515
Name: Hai Nam Ngo
Date Created: 3/28/2023
Date Modified: 3/28/2023
Problem: Week 5 Question 2
Problem Description:  
Write a function printlistBackward that recursively outputs the items in a list in reverse order. 
(Recursively Print a List Backward)

*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int a;
    struct node *next;
};

typedef struct node Node;
typedef Node *nodePtr;

void printList(nodePtr currentPtr)
{
    while(currentPtr!=NULL)
    {
        printf("%d -> ",currentPtr->a);
        currentPtr=currentPtr->next;
    }
    printf("NULL");
}

void printListBackward(nodePtr currentPtr)
{
	if(currentPtr==NULL)
		return;
	printListBackward(currentPtr->next);
	printf("%d -> ",currentPtr->a);
}


int main()
{
    nodePtr startPtr=NULL, newPtr, currentPtr;
    for(int i=0;i<10;i++)
    {
        newPtr=malloc(sizeof(Node));
        newPtr->a=i;
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
    }
    currentPtr=startPtr;
    printf("The list is \n");
    printList(currentPtr);
	
	printf("\nThe list in reverse order is \n");
	printListBackward(currentPtr);
	printf("NULL");	
} 