/*
Unit Code: COS10007
Unit Name: Developing Technical Software
Student Name: Hai Nam Ngo
Student ID: 103488515
Name of the file: 103488515_LabTest.c
Input: option
Output: Display the menu and 4 options.
Date created: 5/23/2023
Last modified: 5/23/2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

//creat a structure of details
struct laptopModel
{
    char laptopName[20];
    int price;
};

struct laptop
{
    char brandName[20];
    int noOfModels; //maximum number of model is 5
    struct laptopModel details[5];
    struct laptop *next;
};

typedef struct laptop Laptop;
typedef Laptop* LaptopPtr;

//function declarations to ready to be used
void readDetails(Laptop laptop_array[], int arraySize);
int menu();
void displayArray(struct laptop[], int arraySize);
LaptopPtr fillLinkedList(const Laptop laptop_array[], int arraySize);
void displayList(LaptopPtr startPtr);
void findAverage(LaptopPtr startPtr);


//main function to run the program
int main() 
{
    Laptop laptop_array[SIZE];
    int option;
    LaptopPtr startPtr=NULL;

    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tWelcome to Laptop Program\n");

    do 
    {
        option = menu(); //option will be taken from the menu function

        switch (option) 
        {
            case 1:
                readDetails(laptop_array,SIZE); //call readDetails function
                displayArray(laptop_array, SIZE); //call displayArray function
                break;

            case 2:
                startPtr = fillLinkedList(laptop_array, SIZE); //call fillLinkedList function
                break;

            case 3:
                displayList(startPtr); //call displayList function
                break;

            case 4:
                findAverage(startPtr); //call findAverage function
                break;

            case -1:
                printf("------------------------------------------------------------------------\n");
                printf("Exiting the program...\n");
                printf("------------------------------------------------------------------------\n");
                break;
            default:
                printf("Invalid Entry! Please try again! \n");
                break;
        }
    } while (option != -1); //end the program when the user enter "6"
    return 0;
}

//function 1: read details from the text file
void readDetails(Laptop laptop_array[], int arraySize)
{
    //open the text file in reading mode
    FILE* fp = fopen("laptop.txt", "r");
    // if the text file cannot be opened
    if (fp == NULL) 
    {
        printf("Error opening the file\n");
        return;
    }

    //use the for loop to read each line of the file
    for (int i = 0; i < arraySize; i++) 
    {
        fscanf(fp, "%s", laptop_array[i].brandName);
        fscanf(fp, "%d", &laptop_array[i].noOfModels);
        
        for (int j=0; j<laptop_array[i].noOfModels; j++) 
        {
            fscanf(fp, "%s %d", laptop_array[i].details[j].laptopName,&laptop_array[i].details[j].price);
        }
    }
    //close the file
    fclose(fp);
}


//function 2: display the menu
int menu() 
{
    int option;
    printf("------------------------------------------------------------------------\n");
    printf("Enter 1 to display the laptop details \n");
    printf("Enter 2 to add laptop details into a LinkedList \n");
    printf("Enter 3 to display LinkedList  \n");
    printf("Enter 4 to find average prices for a brand \n");
    printf("Enter -1 to exit the program \n");
    printf("Select your option: ");
    scanf("%d", &option);

    //return the option back to the main function
    return option;
}


//function 3: display the array
void displayArray(struct laptop laptop_array[], int arraySize)
{
    for (int i = 0; i < arraySize; i++) 
    {
        printf("-----------------------------------\n");
        printf("Brand Name: %s \n", laptop_array[i].brandName);
        printf("%s has %d models \n", laptop_array[i].brandName, laptop_array[i].noOfModels);
        for (int j=0; j<laptop_array[i].noOfModels; j++) 
        {
            printf("Model Name: %s and Price: %d \n", laptop_array[i].details[j].laptopName, laptop_array[i].details[j].price);
        }
    }
}


//function 4: copy the array details to the linked list
LaptopPtr fillLinkedList(const Laptop laptop_array[], int arraySize)
{
    //declare pointers for the linked list
    LaptopPtr startPtr = NULL;
    LaptopPtr currentPtr = NULL;

    //create a for loop to copy the array to the linked list
    for (int i = 0; i < arraySize; ++i) 
    {
        LaptopPtr newPtr = (LaptopPtr)malloc(sizeof(Laptop));

        strcpy(newPtr->brandName, laptop_array[i].brandName);
        newPtr->noOfModels = laptop_array[i].noOfModels;

        for (int j = 0; j < laptop_array[i].noOfModels; ++j)
        {
            strcpy(newPtr->details[j].laptopName, laptop_array[i].details[j].laptopName);
            newPtr->details[j].price = laptop_array[i].details[j].price;         
        }

        newPtr->next = NULL;

        //if the linked list is empty
        if (startPtr == NULL) 
        {
            //the start pointer points to the first node
            startPtr = newPtr;
        } 
        // if the linked list is not empty
        else 
        {
            //the next of the current pointer points to the new node
            currentPtr->next = newPtr;
        }
        currentPtr = newPtr; //the current pointer points to the new node
    }
    printf("------------------------------------------------------------------------\n");
    printf("The data has transferred to the linked list \n");
    return startPtr; 
}

//function 5: display the linked list
void displayList(LaptopPtr startPtr) 
{
    //while loop will run until the end of the linked list
    while (startPtr != NULL) 
    {
        printf("-----------------------------------\n");
        printf("Brand Name: %s \n", startPtr->brandName);
        printf("%s has %d models \n", startPtr->brandName, startPtr->noOfModels);
        for (int j=0; j < startPtr->noOfModels; j++) 
        {
            printf("Model Name: %s and Price: %d \n", startPtr->details[j].laptopName, startPtr->details[j].price);
        }

    startPtr = startPtr->next;
    }
}


//function 6: find the average score
void findAverage(LaptopPtr startPtr)
{
    char brand_key[20];
    int count = 0;
    double totalPrice = 0;
    LaptopPtr currentPtr = startPtr;
	
	//ask user for the name of the company
    printf("------------------------------------------------------------------------\n");
    printf("Enter a brand name (Dell, Lenovo, Apple, Asus, HP): ");
    scanf("%s", brand_key);
	
	//run through the file
    while (currentPtr != NULL)
    {
		//if the user's input is the same as the data in the file
        if (strcmp(currentPtr->brandName, brand_key) == 0)
        {
			//update the total salary (this is also known as the sum of employees' salary of that company)
            for (int i = 0; i < currentPtr->noOfModels; i++)
            {
                totalPrice += currentPtr->details[i].price;
            }
            count += currentPtr->noOfModels;
        }
        //go to the next node
        currentPtr = currentPtr->next;
    }

	//if count>0, means that it has data to be displayed
    if (count > 0)
    {
		//display the output
        double average = totalPrice / count;
        printf("------------------------------------------------------------------------\n");
        printf("The average price of %s is: %lf\n", brand_key, average);
    }
	//if there is no company name like the user's input
    else
    {
        printf("------------------------------------------------------------------------\n");
        printf("There is no company name like %s\n", brand_key);
    }
}

