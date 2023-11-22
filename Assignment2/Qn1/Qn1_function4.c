/*
Unit Code: COS10007
Unit Name: Developing Technical Software
Student Name: Hai Nam Ngo
Student ID: 103488515
Name of the file: Qn1_function4.c
Brief explanation: the separate C file for the linked list function, use to transfer the data from the array to the linked list.
Input: None
Output: Data of all players by using the linked list.
Date created: 5/1/2023
Last modified: 5/9/2023
*/

#include "Qn1_struct_function12.h"
#include "Qn1_function34.h"

void linked_list(struct info info[],int arrayLength)
{
    // Bubble sort the array in ascending order
    BubbleSortAsc(info, arrayLength);

    // Define a pointer to the Info struct and declare them as NULL
    typedef struct info Info;
    typedef Info *InfoPtr;
    InfoPtr startPtr = NULL;
    InfoPtr currentPtr = NULL;

    // Iterate through the array and create a new node for each element
    for (int i = 0; i < arrayLength; i++)
    {
        // Allocate memory for a new node and populate its fields with data from the array
        InfoPtr newPtr = (Info*)malloc(sizeof(Info));
        strcpy(newPtr->player, info[i].player);
        newPtr->age = info[i].age;
        newPtr->rank = info[i].rank;
        newPtr->score = info[i].score;
        newPtr->next = NULL;

        // If the linked list is empty, set the start pointer to the new node
        if (currentPtr == NULL)
        {
            startPtr = newPtr;
        }
        // Otherwise, set the next pointer of the current node to the new node
        else
        {
            currentPtr->next = newPtr;
        }

        // Set the current node pointer to the new node
        currentPtr = newPtr;
    }

    // Print the header for the scoreboard
    printf("------------------------------------------------------------------------\n");
    printf("\t\tWelcome to Amazing Player Scoreboard (linked list) \n");
    printf("------------------------------------------------------------------------\n");
    printf("Player\tAge\tRank\tScore \n");

    // Iterate through the linked list and print each node's data
    while (startPtr != NULL)
    {
        printf("%s\t%d\t%d\t%lf \n",
            startPtr->player,
            startPtr->age,
            startPtr->rank,
            startPtr->score);

        // Set the start pointer to the next node in the list
        startPtr = startPtr->next;
    }
}