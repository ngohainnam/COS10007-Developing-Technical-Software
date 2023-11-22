
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct personal
{ 
	char studentName[20]; 
	int studentId; 
}; 
 
struct course
{ 
	char courseName[20]; 
	int courseId; 
}; 
 
struct student
{ 
	struct personal studentInfo; 
	struct course courseInfo; 
	struct student *nextPtr; 
}; 
 
typedef struct student Student; 
typedef Student *StudentPtr; 

void printList(StudentPtr currentPtr)
{
	puts("The list is \n");
	while(currentPtr!=NULL)
	{
		printf("Student Name: %s \n",currentPtr->studentInfo.studentName);
		printf("Course Name: %s \n", currentPtr->courseInfo.courseName);
		printf("Student ID: %d \n",currentPtr->studentInfo.studentId);
		printf("Course ID: %d \n",currentPtr->courseInfo.courseId);
		
		currentPtr=currentPtr->nextPtr;
	}
}

void printfFile(StudentPtr currentPtr)
{
	FILE *fp=fopen("Output.txt","w+");

	while(currentPtr!=NULL)
	{
		fprintf(fp,"Student Name: %s \n",currentPtr->studentInfo.studentName);
		fprintf(fp,"Course Name: %s \n", currentPtr->courseInfo.courseName);
		fprintf(fp,"Student ID: %d \n",currentPtr->studentInfo.studentId);
		fprintf(fp,"Course ID: %d \n",currentPtr->courseInfo.courseId);
		
		currentPtr=currentPtr->nextPtr;
	}
}

void insert(StudentPtr *sPtr, char sName [], char cName[], int sID, int cID)
{
	StudentPtr newPtr; /* pointer to new node*/
	StudentPtr previousPtr; /* pointer to previous node in list*/
	StudentPtr currentPtr; /*	pointer to current node in list*/
	newPtr = malloc( sizeof( Student ));	/* create node*/
	if ( newPtr != NULL )  /* is space available*/
	{
		strcpy(newPtr->studentInfo.studentName,sName);
		strcpy(newPtr->courseInfo.courseName, cName);
		newPtr->studentInfo.studentId=sID;
		newPtr->courseInfo.courseId=cID;
		
		newPtr->nextPtr = NULL; /*	node does not link to another node*/
		previousPtr = NULL;
		currentPtr = *sPtr;
		/* loop to find the correct location in the list*/
		while ( currentPtr != NULL && sID > currentPtr ->studentInfo.studentId)
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
		printf( "No memory available.\n");
	} /* end else*/
} /* end function insert*/
	

void delete(StudentPtr *sPtr, char sName[])
{
	StudentPtr previousPtr; /* pointer to previous node in list*/
	StudentPtr currentPtr; /* pointer to current node in list*/
	//StudentPtr tempPtr=*sPtr; /* temporary node pointer*/
	/* delete first node*/
	StudentPtr tempPtr=*sPtr;
	if ( strcmp(sName,(*sPtr )-> studentInfo.studentName)==0)
	{
		*sPtr = ( *sPtr )->nextPtr; /* de-thread the node*/
		free( tempPtr ); /* free the de-threaded node*/
	} /* end if*/
	else
	{
		previousPtr = *sPtr;
		currentPtr = ( *sPtr )->nextPtr;
		/* loop to find the correct location in the list*/
		while ( currentPtr != NULL && strcmp(currentPtr -> studentInfo.studentName,sName)!=0)
		{
			previousPtr = currentPtr; /* walk to ...*/
			currentPtr = currentPtr -> nextPtr; /*... next node*/
		} /* end while*/
		/* delete node at currentPtr*/
		if ( currentPtr != NULL )
		{
			tempPtr = currentPtr;
			previousPtr->nextPtr = currentPtr->nextPtr;
			free( tempPtr );
		} /* end if*/
	} /* end else*/
} /* end function delete*/



void update(StudentPtr *sPtr, char sName[])
{
	StudentPtr previousPtr; /* pointer to previous node in list*/
	StudentPtr currentPtr; /* pointer to current node in list*/
	char cName[20];
	int cID, newSID;
	
	
	/* delete first node*/
	StudentPtr tempPtr=*sPtr;
	if ( strcmp(sName,(*sPtr )-> studentInfo.studentName)==0)
	{
		*sPtr = ( *sPtr )->nextPtr; /* de-thread the node*/
		strcpy(cName, (*sPtr )->courseInfo.courseName);
		cID=(*sPtr)->courseInfo.courseId;
		free( tempPtr ); /* free the de-threaded node*/
	} /* end if*/
	else
	{
		previousPtr = *sPtr;
		currentPtr = ( *sPtr )->nextPtr;
		/* loop to find the correct location in the list*/
		while ( currentPtr != NULL && strcmp(currentPtr -> studentInfo.studentName,sName)!=0)
		{
			previousPtr = currentPtr; /* walk to ...*/
			currentPtr = currentPtr -> nextPtr; /*... next node*/
		} /* end while*/
		/* delete node at currentPtr*/
		if ( currentPtr != NULL )
		{
			tempPtr = currentPtr;
			previousPtr->nextPtr = currentPtr->nextPtr;
			strcpy(cName, currentPtr->courseInfo.courseName);
			cID=currentPtr->courseInfo.courseId;
			free( tempPtr );
		} /* end if*/
	} /* end else*/
	printf("Enter a new student ID for %s\n",sName);
	scanf("%d",&newSID);
	insert(sPtr, sName, cName, newSID, cID);
} 

int main()
{
	char sName[20], cName[20];
	int sID, cID;
	FILE *fp=fopen("student.txt","r");
	if(fp==NULL)
	{
		printf("Error opening the file \n");
		return -1;
	}
	
	StudentPtr startPtr=NULL;
	
	while(!feof(fp))
	{
		fscanf(fp,"%s",sName);
		fscanf(fp,"%s",cName);
		fscanf(fp,"%d",&sID);
		fscanf(fp,"%d",&cID);
		insert(&startPtr,sName,cName,sID,cID);
	}	
	printList(startPtr);

	//part d below
	printf("Enter a name to delete \n");
	scanf("%s", sName);
	delete(&startPtr, sName);
	
	printf("The list after deleting %s \n", sName);
	printList(startPtr);
	
	
	//part e below
	printf("Enter a name to update student's ID \n");
	scanf("%s", sName);
	update(&startPtr, sName);
	printf("The list after modifying student ID of %c\n", sName);
	printList(startPtr);
}