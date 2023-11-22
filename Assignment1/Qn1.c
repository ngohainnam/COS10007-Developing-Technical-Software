/*
Unit Code: COS10007
Unit Name: Developing Technical Software
Student Name: Hai Nam Ngo
Student ID: 103488515
Name of the file: Ass1_Qn1.c
Brief explanation: print out five letters from my name in alphabetical order
Input: No input required
Output: A -> G -> H -> N -> O -> NULL (Hai Nam Ngo -> N G O H A  -> A G H N O)
Date created: 3/22/2023
Last modified: 3/28/2023
*/

#include <stdio.h>
#include <stdlib.h>


/*structure listnode*/
struct studentname
{
	char letter; /* each listNode contains a character from the student name*/
	struct studentname *next; /*pointer to the next node*/
};/*end listnode*/


typedef struct studentname STUDENTName; /* synonym for struct studentname*/
typedef STUDENTName *STUDENTNamePtr; /* synonym for studentname* */

//prototype
void displayList(STUDENTNamePtr currentPtr,STUDENTNamePtr startPtr);

//function for print out the output
void displayList(STUDENTNamePtr currentPtr,STUDENTNamePtr startPtr)
{
	printf("Five letters in my name in alphabetical order: \n");
	currentPtr=startPtr;
	while(currentPtr!=NULL)
	{
		printf(" %c ->",currentPtr->letter);
		currentPtr=currentPtr->next;
	}
	printf(" NULL");
}

/*start main*/
int main(void)
{
	STUDENTNamePtr ptr1;
	STUDENTNamePtr ptr2;
	STUDENTNamePtr ptr3;
	STUDENTNamePtr ptr4;
	STUDENTNamePtr ptr5;  
	STUDENTNamePtr startPtr;  
	STUDENTNamePtr currentPtr;  
	
	/*Insert the first letter: N*/
	ptr1=(STUDENTName*)malloc(sizeof(STUDENTName));
	ptr1->letter='N';
	ptr1->next=NULL;
	startPtr=ptr1;
	
	/*Insert the second letter: G...should go before N*/
	ptr2=(STUDENTName*)malloc(sizeof(STUDENTName));
	ptr2->letter='G';
	ptr2->next=ptr1;
	startPtr=ptr2;
	
	/*Insert the third letter: O...should go after N*/
	ptr3=(STUDENTName*)malloc(sizeof(STUDENTName));
	ptr3->letter='O';
	ptr3->next=NULL;
	ptr1->next=ptr3; //this means the next node for N will be O
	startPtr=ptr3;
	
	/*Insert the fourth letter: H...should go between G and N*/
	ptr4=(STUDENTName*)malloc(sizeof(STUDENTName));
	ptr4->letter='H';
	ptr4->next=ptr1;
	ptr2->next=ptr4;
	startPtr=ptr4;
	
	/*Insert the fifth letter: A...should go before G*/
	ptr5=(STUDENTName*)malloc(sizeof(STUDENTName));
	ptr5->letter='A';	
	ptr5->next=ptr2;
	startPtr=ptr5;
	
	displayList(currentPtr,startPtr);
}
	

