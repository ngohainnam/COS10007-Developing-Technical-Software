/*
Unit Code: COS10007
Unit Name: Developing Technical Software
Student Name: Hai Nam Ngo
Student ID: 103488515
Name of the file: Qn1_function2.c 
Brief explanation: a separate c file for two sorting techniques- bubble and selection.
Input: sort_option, sort_order.
Output: the list in order which is chosen by the user.
Date created: 5/1/2023
Last modified: 5/9/2023
*/

//include libraries
#include "Qn1_struct_function12.h"
#include "Qn1_function34.h"

//function 2 main: sort by player name
void sort(struct info info[], int arrayLength)
{
	int sort_option;
	char sort_order[5];

	//print out to ask the user about the sorting technique
    printf("------------------------------------------------------------------------\n");
	printf("Select a sorting techniques: \n");
	printf("Press '1' for Bubble Sort \n");
	printf("Press '2' for Selection Sort \n");
    printf("Select your option: ");
	scanf("%d",&sort_option);

	//print out to ask the user about the sorting order
    printf("------------------------------------------------------------------------\n");
	printf("Select your preferred order by name: \n");
	printf("Type 'asc' for ascending order. \n");
	printf("Type 'desc' for descending order. \n");
    printf("Select your option: ");
	scanf("%s",sort_order);

	switch(sort_option)
	{
        case 1:
            if(strcmp(sort_order, "asc") == 0) //if user choose ascending order by using bubble sort
                BubbleSortAsc(info,SIZE);

            else if(strcmp(sort_order, "desc") == 0) //if user choose descending order by using bubble sort
                BubbleSortDesc(info,SIZE);
            break;
		
		case 2:
            if(strcmp(sort_order, "asc") == 0) //if user choose ascending order by using selection sort
                SelectionSortAsc(info,SIZE);

            else if(strcmp(sort_order, "desc") == 0) //if user choose descending order by using selection sort
                SelectionSortDesc(info,SIZE);
            break;
		
		default:
			printf("Please type a valid option \n"); //if user choose an invalid option
		break;
	}
}

//function 2 mini: bubble sort
//bubble sort in ascending order
void BubbleSortAsc(struct info info[], int arrayLength) 
{
    // Open the file in write mode
    FILE* fp = fopen("data.txt", "w");
    if (fp == NULL) 
    {
        printf("Error opening file to update.\n");
        return;
    }

    // Bubble sort algorithm
    for (int i = 0; i < (arrayLength - 1); ++i) 
    {
        for (int j = 0; j < arrayLength - 1 - i; ++j) 
        {
            if (strcmp(info[j].player, info[j+1].player) > 0)
            {
                struct info temp = info[j+1];
                info[j+1] = info[j];
                info[j] = temp;
            }
        }
    }
    // Write the sorted data to the file
    for (int i = 0; i < arrayLength; i++) 
    {
        fprintf(fp, "%s %d %d %lf\n",
            info[i].player,
            info[i].age,
            info[i].rank,
            info[i].score);
    }
    // Close the file
    fclose(fp);
}


//bubble sort in descending order
void BubbleSortDesc(struct info info[], int arrayLength)
{
	int i, j;
	struct info temp;

    // Open the file in write mode
    FILE* fp = fopen("data.txt", "w");
    if (fp == NULL) 
    {
        printf("Error opening file to update.\n");
        return;
    }

	for (i = 0; i < (arrayLength - 1); ++i)
	{
		for (j = 0; j < arrayLength - 1 - i; ++j)
		{
			// if the current element's player name comes before the next element's player name
            // swap the current element with the next element to move the bigger element to the left
			if (strcmp(info[j].player, info[j+1].player) < 0)
			{
				temp = info[j+1];
				info[j+1] = info[j];
				info[j] = temp;
			}
		}
	}
    // Write the sorted data to the file
    for (int i = 0; i < arrayLength; i++) 
    {
        fprintf(fp, "%s %d %d %lf\n",
            info[i].player,
            info[i].age,
            info[i].rank,
            info[i].score);
    }
    // Close the file
    fclose(fp);
}

//function 2 mini: selection sort
//selection sort in ascending order
void SelectionSortAsc(struct info info[], int arrayLength)
{
    // Open the file in write mode
    FILE* fp = fopen("data.txt", "w");
    if (fp == NULL) 
    {
        printf("Error opening file to update.\n");
        return;
    }

	for (int i = 0; i < arrayLength-1; ++i) // loop through the unsorted array
	{
		int j, min; 
	    struct info temp; // create temporary struct variable
		min = i;
		for (j = i+1; j < arrayLength; ++j) // loop through the remaining unsorted array
		{
			if (strcmp(info[j].player, info[min].player) < 0) // compare the player name of the current element with the minimum element
			min = j; // if the current element is smaller, update the minimum index
		}
		temp = info[i]; // swap the minimum element with the first unsorted element
		info[i] = info[min];
		info[min] = temp;
	}
    // Write the sorted data to the file
    for (int i = 0; i < arrayLength; i++) 
    {
        fprintf(fp, "%s %d %d %lf\n",
            info[i].player,
            info[i].age,
            info[i].rank,
            info[i].score);
    }
    // Close the file
    fclose(fp);
}


//selection sort in descending order
void SelectionSortDesc(struct info info[], int arrayLength)
{
    int i;
    // Open the file in write mode
    FILE* fp = fopen("data.txt", "w");
    if (fp == NULL) 
    {
        printf("Error opening file to update.\n");
        return;
    }
    // Loop through the array, starting from the first element
    for (i = 0; i < arrayLength-1; ++i)
    {
        int j, max;
        struct info temp;
        // Set the current element as the minimum
        max = i;
        // Find the minimum element in the rest of the array
        for (j = i+1; j < arrayLength; ++j)
        {
            if (strcmp(info[j].player, info[max].player) > 0)
            // If the current element is greater than the maximum, update the maximum
            max = j;
        }
        // Swap the maximum element with the current element
        temp = info[i];
        info[i] = info[max];
        info[max] = temp;
    }
    // Write the sorted data to the file
    for (int i = 0; i < arrayLength; i++) 
    {
        fprintf(fp, "%s %d %d %lf\n",
            info[i].player,
            info[i].age,
            info[i].rank,
            info[i].score);
    }
    // Close the file
    fclose(fp);
}

