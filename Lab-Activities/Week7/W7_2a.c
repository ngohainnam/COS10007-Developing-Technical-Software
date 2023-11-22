/*
Unit Code: COS10007
Unit Name: Developing Techinical Software
Student ID: 103488515
Name: Hai Nam Ngo
Date Created: 04/20/2023
Date Modified: 04/20/2023
Problem: Week 7 Question 2b
Problem Description: create an array of size 5 students. Then write a
complete C program to sort the students array based on the students rank using bubble sort.
*/

#include <stdio.h>
#include <stdlib.h>

struct student{
	char name[10];
	int rank;
};

#define SIZE 5

void BubbleSort(struct student a[], int array_size)
{
	int i, j;
	struct student temp;
	for (i = 0; i < (array_size - 1); ++i)
	{
		for (j = 0; j < array_size - 1 - i; ++j)
		{
			if (a[j].rank > a[j+1].rank)
			{
				temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
			}
		}
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
		
	BubbleSort(a,SIZE);

	printf("The sorted array is \n");
	for(int i=0;i<SIZE;i++)
	{
		printf("Student's name: %s \t Rank %d \n",a[i].name,a[i].rank);
	}
	return 0;
}