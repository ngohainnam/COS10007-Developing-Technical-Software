#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Merge(int A[],int L[],int nL,int R[],int nR) {
	int i,j,k;
	i = 0; j = 0; k =0;

	while(i<nL && j< nR) 
	{
		if(L[i]  < R[j]) 
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


void MergeSort(int *A,int n) {
	int mid,i, *L, *R;
	if(n < 2) return; // base condition. If the array has less than two element, do nothing. 

	mid = n/2;  // find the mid index. 
	L = (int*)malloc(mid*sizeof(int)); 
	R = (int*)malloc((n- mid)*sizeof(int)); 
	
	for(i = 0;i<mid;i++) 
		L[i] = A[i]; // creating left subarray
	for(i = mid;i<n;i++) 
		R[i-mid] = A[i]; // creating right subarray

	MergeSort(L,mid);  // sorting the left subarray
	MergeSort(R,n-mid);  // sorting the right subarray
	Merge(A,L,mid,R,n-mid);  // Merging L and R into A as sorted list.
    free(L);
    free(R);
}

int main() {
	int array[10],i;
	srand(time(NULL));
	for (i=0; i<10; i++)
		array[i]=rand()%10;
	printf("Array before sorting \n");
	for (i=0; i<10; i++)
		printf("%d ", array[i]);
	MergeSort(array,10);
	printf("\nArray after sorting \n");
	for(i = 0;i < 10;i++) 
		printf("%d ",array[i]);
	printf("\n");
	return 0;
}