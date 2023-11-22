#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "W9_Qn2_header.h"

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