/*
Unit Code: COS10007
Unit Name: Developing Techinical Software
Student ID: 103488515
Name: Hai Nam Ngo
Date Created: 05/01/2023
Date Modified: 05/01/2023
Problem: Week 8 Question 2a
Problem Description:
Linear Search
a. The function should receive an integer array, a search key and the size of the
array as arguments.
b. If the search key is found, return the location in the array where the search key is
found; otherwise, return -1.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

/*The function receive an integer array, a search key and the size of the
array as arguments*/
int linearSearch(const int array[], int key,int array_size)
{
	int i;

/*/*If the search key is found, return the location in the array where the search key is
found; otherwise, return -1*/
	for (i=0; i<array_size; i++)
	{
		if (array[i]==key)
		{
			printf("Found value in element: %d",i);
			return i;
		}
	}
	printf("Value not found.\n");
	return -1;
}


int main() 
{
	int array[SIZE],i,key;
	srand(time(NULL));
	for (i=0; i<SIZE; i++)
		array[i]=rand()%100;


//print out the array
	printf("The array: \n");
	for (i=0; i<SIZE; i++)
	{
		printf("%d ", array[i]);
	}

	printf("\nEnter integer search key: ");
	scanf("%d",&key);
	
	linearSearch(array,key,SIZE);
	return 0;
}
