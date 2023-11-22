#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}
int partition(int array[], int start, int end)
{
	int pivot = array[end];
	int pIndex=start;
	for(int i=start; i < end; i++)
	{
		if(array[i] <= pivot)
		{
			swap(&array[i],&array[pIndex]);
			pIndex++;
		}
	}
	swap(&array[pIndex],&array[end]);
	return pIndex;
	
}
 
void Quicksort (int array[], int start, int end)
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
	int array[10],i;
	srand(time(NULL));
	for (i=0; i<10; i++)
		array[i]=rand()%10;
	printf("Array before sorting \n");
	for (i=0; i<10; i++)
		printf("%d ", array[i]);
	Quicksort(array, 0, 9);
	printf("\nArray after sorting \n");
	for (i=0; i<10; i++)
		printf("%d ", array[i]);
}




