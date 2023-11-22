/*
Unit Code: COS10007
Unit Name: Developing Techinical Software
Student ID: 103488515
Name: Hai Nam Ngo
Date Created: 04/04/2023
Date Modified: 04/04/2023
Problem: Week 6 Question 1
Problem Description: Write a program that concatenates two linked lists of characters.
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

void concantenate(nodePtr startPtr1,nodePtr startPtr2)
{
	nodePtr temp;
	temp=startPtr1;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=startPtr2;
	
		
}

int main()
{
    nodePtr startPtr1=NULL, startPtr2=NULL, newPtr, currentPtr;
    char x='A';
    for(int i=0;i<10;i++)
    {
        newPtr=malloc(sizeof(Node));
        newPtr->a=x;
        newPtr->next=NULL;
        
        if(startPtr1==NULL)
        {
            startPtr1=newPtr;
            currentPtr=newPtr;
        }
        else
        {
            currentPtr->next=newPtr;
            currentPtr=newPtr;
        }
        x++;
    }
	
	x='M';
    for(int i=0;i<10;i++)
    {
        newPtr=malloc(sizeof(Node));
        newPtr->a=x;
        newPtr->next=NULL;
        
        if(startPtr2==NULL)
        {
            startPtr2=newPtr;
            currentPtr=newPtr;
        }
        else
        {
            currentPtr->next=newPtr;
            currentPtr=newPtr;
        }
        x++;
    }
	
    currentPtr=startPtr1;
    printf("The list 1 is \n");
    printList(currentPtr);
	
	currentPtr=startPtr2;
    printf("\nThe list 2 is \n");
    printList(currentPtr);
	
	printf("\nThe combined list is \n");
	concantenate(startPtr1,startPtr2);
	printList(startPtr1);
	
	return 0;
} 