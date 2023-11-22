/*
Unit Code: COS10007
Unit Name: Developing Technical Software
Student Name: Hai Nam Ngo
Student ID: 103488515
Name of the file: Ass1_Qn2.c
Brief explanation: Create an Employee Management System with 8 functions including the menu
Input: Name, age, id, comany, salary, search
Output: Display the menu and 8 functions.
Date created: 3/22/2023
Last modified: 4/02/2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//self-referential structure 
struct personTag
{
	char name[20];
	int age;
};

struct officialTag
{
	int deptId;
	char cmpName[20];
	double salary;
};

struct employeeTag
{
	struct personTag personalInfo;
	struct officialTag officialInfo;
	struct employeeTag *next;
};

typedef struct employeeTag EmployeeTag;
typedef EmployeeTag *EmployeeTagPtr;


//readfile function: to open the employee.txt and read the details and save it in linkedlist
EmployeeTagPtr readFile()
{
    FILE *fp=fopen("employee.txt","r");
    if(fp==NULL)
    {
        printf("Error opening the file \n");
        return NULL;
    }

    EmployeeTagPtr startPtr=NULL;
    EmployeeTagPtr currentPtr=NULL;
    EmployeeTagPtr newPtr=NULL;

    // Read the first employee from the file
    newPtr = (EmployeeTag*)malloc(sizeof(EmployeeTag));
    fscanf(fp,"%s",newPtr->personalInfo.name);
    fscanf(fp,"%d",&newPtr->personalInfo.age);
    fscanf(fp,"%d",&newPtr->officialInfo.deptId);
    fscanf(fp,"%s",newPtr->officialInfo.cmpName);
    fscanf(fp,"%lf",&newPtr->officialInfo.salary);
    newPtr->next = NULL;
    startPtr = newPtr;
    currentPtr = newPtr;

    // Read the remaining employees from the file
    while (!feof(fp))
    {
        newPtr = (EmployeeTag*)malloc(sizeof(EmployeeTag));
        fscanf(fp,"%s",newPtr->personalInfo.name);
        fscanf(fp,"%d",&newPtr->personalInfo.age);
        fscanf(fp,"%d",&newPtr->officialInfo.deptId);
        fscanf(fp,"%s",newPtr->officialInfo.cmpName);
        fscanf(fp,"%lf",&newPtr->officialInfo.salary);
        newPtr->next = NULL;

        // Insert the new employee in alphabetical order based on name
        if (strcmp(newPtr->personalInfo.name, startPtr->personalInfo.name) < 0)
        {
            newPtr->next = startPtr;
            startPtr = newPtr;
        }
        else
        {
            currentPtr = startPtr;
            while (currentPtr->next != NULL && strcmp(newPtr->personalInfo.name, currentPtr->next->personalInfo.name) > 0)
            {
                currentPtr = currentPtr->next;
            }
            newPtr->next = currentPtr->next;
            currentPtr->next = newPtr;
        }
    }

    // Close the file
    fclose(fp);
    return startPtr;
}


//this function is used to display employee list to the screen
void displayEmployees(EmployeeTagPtr startPtr)
{
	printf("------------------------------------------------------------------------\n");
	printf("\t\tList of all employees (alphabetical order)\n");
	printf("Name\tAge\tID\tCompany\tSalary \n");
	
	// loop through the list and print each node
	while (startPtr != NULL)
	{
		printf("%s\t%d\t%d\t%s\t%lf \n",
		startPtr->personalInfo.name,
		startPtr->personalInfo.age,
		startPtr->officialInfo.deptId,
		startPtr->officialInfo.cmpName,
		startPtr->officialInfo.salary); 
		
		startPtr = startPtr->next;
	}
}


//this function is created to update file: insert new employee to the list
void updateFile(EmployeeTagPtr startPtr)
{
    // open the file in append mode
    FILE *fp = fopen("employee.txt", "a");
    if (fp == NULL) 
	{
        printf("Error opening file.\n");
        return;
    }

    // prompt the user for new employee's details
    EmployeeTagPtr newEmployee = malloc(sizeof(EmployeeTag));

    printf("Enter new employee details:\n");
    printf("ID: ");
    scanf("%d", &newEmployee->officialInfo.deptId);
    printf("Name: ");
    scanf("%s", newEmployee->personalInfo.name);
	printf("Age: ");
	scanf("%d",&newEmployee->personalInfo.age);
    printf("Company name: ");
    scanf("%s", newEmployee->officialInfo.cmpName);
    printf("Salary: ");
    scanf("%lf", &newEmployee->officialInfo.salary);

    // write the new data at the end of the file
    fprintf(fp, "%s\t%d\t%d\t%s\t%lf\n",
        newEmployee->personalInfo.name,
		newEmployee->personalInfo.age,
        newEmployee->officialInfo.deptId,
        newEmployee->officialInfo.cmpName,
        newEmployee->officialInfo.salary); 

    // close the file
    fclose(fp);

    // add the new employee to the LinkedList
    // find the last node in the LinkedList
    EmployeeTagPtr currentPtr = startPtr;
    while (currentPtr->next != NULL) 
	{
        currentPtr = currentPtr->next;
    }
    // add the new node to the end of the LinkedList
    currentPtr->next = newEmployee;
    newEmployee->next = NULL;   
	
	printf("------------------------------------------------------------------------\n");
	printf("Update File Completed.\n");
}


//main function to link all of the functions together
int main()
{
    int option;
	
	//print out welcome message
    printf("------------------------------------------------------------------------\n");
    printf("\t\tWelcome to The Employee Management System \n");
    EmployeeTagPtr startPtr = readFile();

    do
    {
		//option is taken from the menu function
        option = menu();
        switch(option)
        {   
            case 1:
                displayEmployees(startPtr);
                break;
            
            case 6:
				updateFile(startPtr);
                break;
                
            case 7:
			    printf("------------------------------------------------------------------------\n");
                printf("Thank you for using the Employee Management System. Exiting the program.\n");
				printf("------------------------------------------------------------------------\n");
                break;
                
            default:
                printf("Invalid option selected. Please try again.\n");
                break;
        }
    } while (option != 7);

    return 0;
}



	