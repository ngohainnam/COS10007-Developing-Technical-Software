/*
Unit Code: COS10007
Unit Name: Developing Techinical Software
Student ID: 103488515
Name: Hai Nam Ngo
Date Created: 04/20/2023
Date Modified: 04/20/2023
Problem: Week 7 Question 2b
Problem Description: Using the veg structure, create an array of size 5. Then write a complete C
program to sort the array based on the item’s price by using merge Sort
*/

#include <stdio.h>
#include <stdlib.h>

struct veg {
	char item[10];
	int price;
};

#define SIZE 5


void Merge(struct veg A[],struct veg L[],int nL,struct veg R[],int nR) {
	int i,j,k;
	i = 0; j = 0; k =0;

	while(i<nL && j< nR) 
	{
		if(L[i].price < R[j].price) 
		{
			A[k] = L[i];
			i++;
		}
		else 
		{
			A[k] = R[j];
			j++;
		}
		k++;
	}
	while(i < nL) 
	{
		A[k] = L[i];
		k++;
		i++;
	}
	while(j < nR)
	{
		A[k] = R[j];
		k++;
		j++;
	}
}

void MergeSort(struct veg *A,int n) {
	int mid,i;
	if(n < 2) return;

	mid = n/2;  
	
	struct veg *L = (struct veg*) malloc(mid*sizeof(struct veg));
	struct veg *R = (struct veg*) malloc((n - mid)*sizeof(struct veg));

	
	for(i = 0;i<mid;i++) 
		L[i] = A[i]; 
	
	for(i = mid;i<n;i++) 
		R[i-mid] = A[i]; 

	MergeSort(L,mid);  
	MergeSort(R,n-mid);  
	Merge(A,L,mid,R,n-mid);  
    free(L);
    free(R);
}

int main()
{
	struct veg A[SIZE];
	for (int i=0;i<SIZE;i++)
	{
		printf("Enter the item: \n");
		scanf("%s",A[i].item);
		printf("Enter the price: \n");
		scanf("%d", &A[i].price);
	}
	
	printf("The unsorted array is \n");
	for(int i=0;i<SIZE;i++)
	{
		printf("Item: %s \t\t Price $%d \n",A[i].item,A[i].price);
	}
		
	MergeSort(A,SIZE);

	printf("The sorted array is \n");
	for(int i=0;i<SIZE;i++)
	{
		printf("Item: %s \t\t Price $%d \n",A[i].item,A[i].price);
	}
	return 0;
}