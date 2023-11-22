

#include <stdio.h>
#include <stdlib.h>

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

int main()
{
	FILE *fp=fopen("student.txt","r");
	if(fp==NULL)
	{
		printf("Error opening the file \n");
		return -1;
	}
	
	StudentPtr startPtr=NULL;
	
	startPtr=(Student*)malloc(sizeof(Student));
	fscanf(fp,"%s",startPtr->studentInfo.studentName);
	fscanf(fp,"%s",startPtr->courseInfo.courseName);
	fscanf(fp,"%d",&startPtr->studentInfo.studentId);
	fscanf(fp,"%d",&startPtr->courseInfo.courseId);
	startPtr->nextPtr=NULL;
	printList(startPtr);
}
	