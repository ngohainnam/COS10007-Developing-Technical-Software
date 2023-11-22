/*
Unit Code: COS10007
Unit Name: Developing Technical Software
Student Name: Hai Nam Ngo
Student ID: 103488515
Name of the file: Qn1_function3.c 
Brief explanation: a separate c file for searching players in two ways, linear and binary search.
Input: search_key, search_option.
Output: One specific player is found or not.
Date created: 5/1/2023
Last modified: 5/9/2023
*/

#include "Qn1_struct_function12.h"
#include "Qn1_function34.h"

//function 3 main: search by  string
//user can select linear or binary

int searching(struct info info[],int i,int low,int high, int arrayLength)
{
    printf("------------------------------------------------------------------------\n");
    printf("Enter the player name to search: ");
    char search_key[5];
    scanf("%s",search_key); //read the user's input for player name

    printf("------------------------------------------------------------------------\n");
    printf("Select the searching method: \n");
    printf("Press '1' for linear search \n");
    printf("Press '2' for binary search \n");
    printf("Select your option: "); //ask the user to select the searching method
    int search_option;
    scanf("%d",&search_option); //read the user's input for searching method

    switch(search_option)
    {
        case 1:
            linear_search(search_key,info,0,arrayLength); //if user choose linear search, then call linear search function
            break;
            
        case 2:
            binary_search(search_key,info,0,arrayLength-1); //low=0 and high=arrayLength-1
            break;
    }
    return -1;
}

//function 3 mini: linear search
int linear_search(const char *search_key, struct info info[],int i, int arrayLength) 
{
    if (i > arrayLength) { //if the index is greater than array length, then no results are returned
        printf("------------------------------------------------------------------------\n");
        printf("No result found. \n");
        return -1;
    }
    else if (strcmp(info[i].player, search_key) == 0) 
    {
        printf("------------------------------------------------------------------------\n");
        printf("Result found: \n");
        printf("%s\t%d\t%d\t%lf \n",
        info[i].player,
        info[i].age,
        info[i].rank,
        info[i].score);
        return i;
    }
    else 
    {
        return linear_search(search_key, info,i+1, arrayLength); //function called itself (recursive)
    }
}


//function 3 mini: binary search
int binary_search(const char *search_key, struct info info[], int low, int high)
{
    BubbleSortAsc(info, SIZE);

    if (low > high)
    {
        printf("------------------------------------------------------------------------\n");
        printf("No result found. \n");
        return -1;
    }
    else
    {
        int middle = (low + high) / 2; //find the middle of the array
        if (strcmp(search_key, info[middle].player) == 0) //if the search key is found
        {
            //print out the result
            printf("------------------------------------------------------------------------\n");
            printf("Result found: \n");
            printf("%s\t%d\t%d\t%lf \n",
            info[middle].player,
            info[middle].age,
            info[middle].rank,
            info[middle].score);
            return middle; 
        }
        else if (strcmp(search_key, info[middle].player) < 0) //if the search key is less than the middle
        {
            return binary_search(search_key, info, low, middle - 1); //call the function to search the left sub-array
        }
        else //if the search key is greater than the middle
        {
            return binary_search(search_key, info, middle + 1, high); //call the function to search the right sub-array
        }
    }
}


