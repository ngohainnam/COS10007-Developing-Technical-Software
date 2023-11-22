/*
Unit Code: COS10007
Unit Name: Developing Techinical Software
Student ID: 103488515
Name: Hai Nam Ngo
Date Created: 04/20/2023
Date Modified: 04/20/2023
Problem: Week 7 Question 2b
Problem Description: create an array of size 5 students. Then write a
complete C program to sort the students array based on the students rank using selection sort.
*/

#include <stdio.h>
#include <stdlib.h>

struct student{
	char name[10];
	int rank;
};

#define SIZE 5

void SelectionSort(struct student a[], int array_size)
{
	int i;
	for (i = 0; i < array_size-1; ++i)
	{
		int j, min;
		struct student temp;
		min = i;
		for (j = i+1; j < array_size; ++j)
		{
			if (a[j].rank < a[min].rank)
			min = j;
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
}

int main()
{
	struct student a[SIZE];
	for (int i=0;i<SIZE;i++)
	{
		printf("Enter student's name \n");
		scanf("%s",a[i].name);
		printf("Enter student's rank \n");
		scanf("%d", &a[i].rank);
	}
	
	printf("The unsorted array is \n");
	for(int i=0;i<SIZE;i++)
	{
		printf("Student's name: %s \t Rank %d \n",a[i].name,a[i].rank);
	}
		
	SelectionSort(a,SIZE);

	printf("The sorted array is \n");
	for(int i=0;i<SIZE;i++)
	{
		printf("Student's name: %s \t Rank %d \n",a[i].name,a[i].rank);
	}
	return 0;
}