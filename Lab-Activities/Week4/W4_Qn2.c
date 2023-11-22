/*
Unit Code: COS10007
Unit Name: Developing Techinical Software
Student ID: 103488515
Name: Hai Nam Ngo
Date Created: 3/24/2023
Date Modified: 3/24/2023
Problem: Week 4 Question 2
Problem Description: Insert a string and print it in reverse.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct reverse
{
	char letter;
	struct reverse *next;
};

typedef struct reverse Reverse;
typedef Reverse *reversePtr;

void pushPop(reversePtr topPtr, char str1[], char str2[], int len);

int main()
{
	reversePtr topPtr=NULL;
	char str1[20], str2[20]={0};
	int len;
	
	printf("Enter a string \n");
	gets(str1);
	
	len=strlen(str1);
	pushPop(topPtr, str1, str2, len);
	printf("The string in reverse order is %s \n", str2);
}

void pushPop(reversePtr topPtr, char str1[], char str2[], int len)
{
	reversePtr newPtr, temPtr;
	char popValue;
	int i=0;
	while(len>0)
	{
		newPtr=(Reverse*)malloc(sizeof(Reverse));
		newPtr->letter=str1[i];
		newPtr->next=topPtr;
		topPtr=newPtr;
		len--;
		i++;
	}
	
	i=0;
	while(topPtr!=NULL)
	{
		temPtr=topPtr;
		popValue=topPtr->letter;
		str2[i]=popValue;
		topPtr=topPtr->next;
		free(temPtr);
		i++;
	}
}