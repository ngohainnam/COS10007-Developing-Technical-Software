/*
Unit Code: COS10007
Unit Name: Developing Techinical Software
Student ID: 103488515
Name: Hai Nam Ngo
Date Created: 04/20/2023
Date Modified: 04/20/2023
Problem: Week 7 Question 3c
Problem Description: Using the veg structure, create an array of size 5. Then write a complete C
program to sort the array based on the item’s price by using Quick sort.
*/

#include <stdio.h>
#include <stdlib.h>

struct veg {
    char item[10];
    int price;
};

#define SIZE 5

void swap(struct veg* a, struct veg* b) 
{ 
    struct veg temp = *a; 
    *a = *b; 
    *b = temp; 
}

int partition(struct veg array[], int start, int end)
{
    struct veg pivot = array[end];
    int pIndex=start;
    for(int i=start; i < end; i++)
    {
        if(array[i].price <= pivot.price)
        {
            swap(&array[i],&array[pIndex]);
            pIndex++;
        }
    }
    swap(&array[pIndex],&array[end]);
    return pIndex;
    
}
 
void Quicksort (struct veg array[], int start, int end)
{
    if (start<end)
    {
        int pIndex=partition(array, start, end);
        Quicksort(array, start, pIndex-1);
        Quicksort(array, pIndex+1, end);
    }
}

int main()
{
    struct veg array[SIZE];
    int start = 0, end = SIZE - 1;
    for (int i=0;i<SIZE;i++)
    {
        printf("Enter the item: \n");
        scanf("%s",array[i].item);
        printf("Enter the price: \n");
        scanf("%d", &array[i].price);
    }
    
    printf("The unsorted array is \n");
    for(int i=0;i<SIZE;i++)
    {
        printf("Item: %s \t Price $%d \n",array[i].item,array[i].price);
    }
        
    Quicksort(array,start,end);

    printf("The sorted array is \n");
    for(int i=0;i<SIZE;i++)
    {
        printf("Item: %s \t Price $%d \n",array[i].item,array[i].price);
    }
    return 0;
}
