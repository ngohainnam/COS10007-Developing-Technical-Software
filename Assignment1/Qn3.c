/*
Unit Code: COS10007
Unit Name: Developing Technical Software
Student Name: Hai Nam Ngo
Student ID: 103488515
Name of the file: 103488515_A_Qn3.c
Brief explanation: This code create a train system that schedules trains, by using structure. There are 6 functions in the code.
Input: No input needed
Output: Train schedule list
Date created: 3/22/2023
Last modified: 4/03/2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Train 
{
    int id;
    time_t schedule;
};


// This function generates random train IDs from 100 to 200 and assigns them to the corresponding trains in the array
void givetrainid(struct Train trains[], int size) 
{
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // For each train in the array, generate a random ID and set its schedule to 0
    for (int i = 0; i < size; i++) 
    {
        trains[i].id = rand() % 101 + 100;  // Generate a random integer between 0 and 100, and add 100 to get a random integer between 100 and 200
        trains[i].schedule = 0;  // Set the train's schedule to 0
    }
}

// This function assigns a random departure time to each train in the array
void givedeparturetime(struct Train trains[], int size) 
{  
    // For each train in the array, set its schedule to the current time plus a random number of seconds between 0 and 9999
    for (int i = 0; i < size; i++) 
    {
        trains[i].schedule = time(NULL) + rand() % 9999;
    }
}

//display the schedule to the screen
void displayschedule(struct Train trains[], int size) 
{
    printf("Train\tTime\n");
    for (int i = 0; i < size; i++) 
    {
        printf("%d\t%s", trains[i].id, ctime(&trains[i].schedule));
    }
}

//display the schedule list in order (from the earliest to the latest)
void reschedule(struct Train trains[], int size)
{
    struct Train swap;
    //going through every train except the last one, because we want to compare the time of two train (two node next to each other)
    for (int i = 0; i < size - 1; i++) 
    {
        //going from the second train two the last train
        for (int j = i + 1; j < size; j++) 
        {
            //if the departure time of the next train is earlier than the current train, swap their positions
            if (trains[i].schedule > trains[j].schedule) 
            {
                //swap place without losing its time value
                swap = trains[i];
                trains[i] = trains[j];
                trains[j] = swap;
            }
        }
    }
}

//the function is created to make the train with the earliest schedule leave the station
void LeaveEarliestTrain(struct Train trains[], int *size) 
{
	int i=0;
	//if size=0, means the stack have no data (no trains)
    if (*size == 0) 
	{
		//print out the information to the screen
        printf("There are no trains left in the station.\n");
        return;
    }
	
	//print out the display to the screen
	printf("----------------------------------------------------\n");
	printf("\t\tAnnouncement\n");
    printf("Train ID %d\nSchedule: %s \nThis train is leaving the station.\n", trains[i].id, ctime(&trains[i].schedule));
	//pop the first train out of the stack
    for (i = 0; i < *size - 1; i++) 
	{
        trains[i] = trains[i + 1];
    }
    (*size)--;
}

//the function is created to make the train with the latest schedule leave the station (emergency)
void EmergencyLeave(struct Train trains[], int *size) 
{
	//if size=0, means the stack have no data (no trains)
    if (*size == 0) 
	{
		//print out the information to the screen
        printf("There are no trains left in the station.\n");
        return;
    }
	//print out the display to the screen
	printf("----------------------------------------------------\n");
	printf("\t\tEmergency Alert\n");
    printf("Train ID %d\nSchedule: %s\nThis train is leaving the station NOW.\n", trains[*size - 1].id, ctime(&trains[*size - 1].schedule));
    (*size)--;
}


int main() 
{
    int size = 10;
    struct Train trains[size];
    
    // Step 1
    givetrainid(trains, size);
    
    // Step 2
    givedeparturetime(trains, size);
    
    // Step 3
    printf("----------------------------------------------------\n");
    printf("\t\tInitial schedule\n");
    printf("----------------------------------------------------\n");
    displayschedule(trains, size);
    
    // Step 4
    reschedule(trains, size);
    
    // Step 3 (repeated)
    printf("----------------------------------------------------\n");
    printf("\t\tFinal schedule\n");
    printf("----------------------------------------------------\n");
    displayschedule(trains, size);
    
    // Step 5
    LeaveEarliestTrain(trains, &size);
    
    //Step 6
    EmergencyLeave(trains, &size);
	
	// Step 3 (repeated)
	printf("----------------------------------------------------\n");
    printf("\tFinal schedule (after two train left)\n");
    printf("----------------------------------------------------\n");
    displayschedule(trains, size);
    
    return 0;
}

