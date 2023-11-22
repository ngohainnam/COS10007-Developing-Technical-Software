/*
Unit Code: COS10007
Unit Name: Developing Technical Software
Student Name: Hai Nam Ngo
Student ID: 103488515
Name of the file: Qn1.c
Brief explanation: the main program for Qn1, use for linking all of the functions together.
Input: option
Output: Display the menu and 5 options.
Date created: 5/1/2023
Last modified: 5/9/2023
*/

//include libraries using the following
#include "Qn1_struct_function12.h"
#include "Qn1_function34.h"

// function 1: Display the details of the array
int displayFile(struct info info[], int arrayLength)
{
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tList of all player\n");
    printf("------------------------------------------------------------------------\n");
    printf("Player\tAge\tRank\tScore \n");

    // loop through the list and print each node
    for (int i = 0; i < SIZE; i++) 
    {
        printf("%s\t%d\t%d\t%lf \n",
               info[i].player,
               info[i].age,
               info[i].rank,
               info[i].score);
    }
    return -1;
}

int main(int i, int low, int high)
{
	struct info info[SIZE];
    int option;

    //open file in reading mode
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening the file \n");
        return -1;
    }

    for (int i = 0; i < SIZE; i++)
    {
        fscanf(fp, "%s %d %d %lf", 
        info[i].player, 
        &info[i].age, 
        &info[i].rank, 
        &info[i].score);
    }
    // close the file
    fclose(fp);
    
    do
    {
        //display the menu
        printf("------------------------------------------------------------------------\n");
        printf("\t\tWelcome to Amazing Player Scoreboard \n");
        printf("------------------------------------------------------------------------\n");
        printf("(1) Displaying all players \n");
        printf("(2) Sorting the data \n");
        printf("(3) Searching for a player \n");
        printf("(4) Inserting array to linked list \n");
        printf("(5) Quit Program \n");
        printf("Select your option: ");
        scanf("%d", &option); // add this line to read the selected option
        
        switch(option)
        {   
            case 1:
            //call displayFile function
                displayFile(info,SIZE);
                break;
            
            case 2:
            //call sort function
                sort(info,SIZE);
            //call displayFile function after sorting
                displayFile(info,SIZE);
                break;
   
            case 3:
            //call search function to search for a player
                searching(info,i,low,high,SIZE);
				break;
				
            case 4:
            //call insert function to insert array to linked list
                linked_list(info,SIZE);
                break;
                
            case 5:
            //print out the goodbye message
			    printf("------------------------------------------------------------------------\n");
                printf("Exiting the program...\n");
				printf("------------------------------------------------------------------------\n");
                break;
            
            //default case for other options that user type in
            default:
                printf("Invalid option selected. Please try again.\n");
                break;
        }
    } while (option != 5); //quit the program when user type in 5

    return 0;
}

	