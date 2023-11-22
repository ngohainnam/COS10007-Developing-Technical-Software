/*
Unit Code: COS10007
Unit Name: Developing Techinical Software
Student ID: 103488515
Name: Hai Nam Ngo
Date Created: 04/20/2023
Date Modified: 04/20/2023
Problem: Week 7 Question 2b
Problem Description: Using the veg structure, create an array of size 5. Then write a complete C
program to sort the array based on the item’s price by using Insertion sort.
*/

#include <stdio.h>
#include <stdlib.h>

struct veg {
	char item[10];
	int price;
};

#define SIZE 5

void insertionSort(struct veg a[], int array_size)
{
	int i, j;
	struct veg index;
	for (i = 1; i < array_size; ++i)
	{
		index = a[i];
		for (j = i; j > 0 && a[j-1].price > index.price; j--)
		a[j] = a[j-1];
		a[j] = index;
	}
}

int main()
{
	struct veg a[SIZE];
	for (int i=0;i<SIZE;i++)
	{
		printf("Enter the item: \n");
		scanf("%s",a[i].item);
		printf("Enter the price: \n");
		scanf("%d", &a[i].price);
	}
	
	printf("The unsorted array is \n");
	for(int i=0;i<SIZE;i++)
	{
		printf("Item: %s \t Price %d \n",a[i].item,a[i].price);
	}
		
	insertionSort(a,SIZE);

	printf("The sorted array is \n");
	for(int i=0;i<SIZE;i++)
	{
		printf("Item: %s \t Price %d \n",a[i].item,a[i].price);
	}
	return 0;
}