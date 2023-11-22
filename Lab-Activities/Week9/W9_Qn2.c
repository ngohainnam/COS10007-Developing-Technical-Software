/*
Unit Code: COS10007
Unit Name: Developing Techinical Software
Student ID: 103488515
Name: Hai Nam Ngo
Date Created: 5/9/2023
Date Modified: 5/9/2023
Problem: Week 9 Question 2
Problem Description: Try to rewrite your program in Week 4 Question 2 into multiple files, e.g. more than one
.c file and .h header.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "W9_Qn2_header.h"

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

