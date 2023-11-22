/* Inserting and deleting nodes in a list */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* self-referential structure*/
struct listNode
{
	int data; /* each listNode contains a character*/
	struct listNode *nextPtr; /*pointer to next node*/
}; /* end structure listNode*/
typedef struct listNode ListNode; /* synonym for struct listNode*/
typedef ListNode *ListNodePtr; /* synonym for ListNode* */
/* prototypes*/
void insert( ListNodePtr *sPtr, int value);
void printList( ListNodePtr currentPtr);
float averagelist( ListNodePtr currentPtr );

int main( void )
{
	ListNodePtr startPtr = NULL; /* initially there are no nodes*/
	srand(time(NULL));
	int item; /* char entered by user*/
		for(int i=0;i<10;i++)
		{
			item=rand()%51;
			insert( &startPtr, item); /* insert item in list*/
		}
			printList( startPtr );
			
			printf("The average of the list is %0.2f\n",averagelist(startPtr));
			
			
} /* end main*/

/* insert a new value into the list in sorted order*/
void insert( ListNodePtr *sPtr, int value )
{
	ListNodePtr newPtr; /* pointer to new node*/
	ListNodePtr previousPtr; /* pointer to previous node in list*/
	ListNodePtr currentPtr; /*	pointer to current node in list*/
	newPtr = malloc( sizeof( ListNode ));	/* create node*/
	if ( newPtr != NULL )  /* is space available*/
	{
		newPtr->data = value; /* place value in node*/
		newPtr->nextPtr = NULL; /*	node does not link to another node*/
		previousPtr = NULL;
		currentPtr = *sPtr;
		/* loop to find the correct location in the list*/
		while ( currentPtr != NULL && value > currentPtr ->data)
		{
			previousPtr = currentPtr; /* walk to ...*/
			currentPtr = currentPtr->nextPtr; /* ... next node*/
		} /* end while*/
		/* insert new node at beginning of list*/
		if ( previousPtr == NULL )
		{
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		} /* end if*/
		else   /* insert new node between previousPtr and currentPtr*/
		{
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		} /* end else*/
	} /* end if*/
	else
	{
		printf( "%c not inserted. No memory available.\n", value );
	} /* end else*/
} /* end function insert*/

/* print the list*/
void printList( ListNodePtr currentPtr )
{
		puts( "The list is: " );
		/* while not the end of the list*/
		while ( currentPtr != NULL )
		{
			printf( "%d --> ", currentPtr->data );
			currentPtr = currentPtr ->nextPtr;
		} /* end while*/
		puts( "NULL\n" );
} /* end function printList */

float averagelist( ListNodePtr currentPtr )
{
		int sum=0,count=0;
		float avg;
		while ( currentPtr != NULL )
		{
			sum=sum+currentPtr->data;
			currentPtr = currentPtr ->nextPtr;
			count++;
		} 
		printf("The sum is %d\n",sum);
		avg=(float)sum/count;
		return avg;
} 