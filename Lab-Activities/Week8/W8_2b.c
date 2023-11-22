/*
Unit Code: COS10007
Unit Name: Developing Technical Software
Student ID: 103488515
Name: Hai Nam Ngo
Date Created: 05/01/2023
Date Modified: 05/01/2023
Problem: Week 8 Question 2a
Problem Description:
Binary Search
a. The function should receive an integer array, a search key, the starting subscript
and ending subscript as arguments.
b. If the search key is found, return the location in the array where the search key is
found; otherwise, return -1.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int binarySearch(const int array[], int key, int low, int high)
{
    int middle,i;
    while (low <= high) 
    {
        middle = (low + high)/2;
        if (key == array[middle]) 
        {
            printf("\nFound value in element: %d",middle);
            return middle;
        }
        else if (key < array[middle]) 
        {
            high = middle - 1;
        }
        else 
        {
            low = middle + 1;
        }
        //print out sub-array
        printf("\nThe sub-array: ");
        for (i = low; i <= high; i++)
        {
            printf("%d ", array[i]);
        }
    }
    printf("\nValue not found.\n");
    return -1;
}


//using selection sort to sort the array
void SelectionSort(int array[], int array_size)
{
	int i;
	for (i = 0; i < array_size-1; ++i)
	{
		int j, min;
		int temp;
		min = i;
		for (j = i+1; j < array_size; ++j)
		{
			if (array[j]< array[min])
			min = j;
		}
		temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}
}

int main() 
{
	int array[SIZE],i,key;
	srand(time(NULL));
	for (i=0; i<SIZE; i++)
		array[i]=rand()%100;


//print out the array in the order from the smallest to largest
	SelectionSort(array,SIZE);
		printf("The array: \n");
	for (i=0; i<SIZE; i++)
	{
		printf("%d ", array[i]);
	}
	
	printf("\nEnter integer search key: ");
	scanf("%d",&key);
	
	int low = 0;
	int high = SIZE - 1;
	binarySearch(array, key, low, high);
	return 0;
}
