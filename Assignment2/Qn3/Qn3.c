/*
Unit Code: COS10007
Unit Name: Developing Technical Software
Student Name: Hai Nam Ngo
Student ID: 103488515
Name of the file: 
Brief explanation: Create a program that manage the stock system and order system of a TV Store which has 10 options in the menu.
Input: option, id, TVname
Output: functions
Date created: 5/3/2023
Last modified: 5/15/2023
*/

//include libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct product
{
    int id;
    char TVname[20];
    struct product *next;
};

typedef struct product Product;
typedef Product *ProductPtr;

typedef struct product Order;
typedef Order *OrderPtr;

typedef struct product Stack;
typedef Stack *StackPtr;

//store the TVs.txt file in the linked list
ProductPtr readTVs()
{
    FILE *fp=fopen("TVs.txt","r");
    if(fp==NULL)
    {
        printf("Error opening the file \n");
        return NULL;
    }

    ProductPtr startPtr=NULL;
    ProductPtr currentPtr=NULL;
    ProductPtr newPtr=NULL;

    // Read the remaining TVs from the file
    while (!feof(fp))
    {
        newPtr = (Product*)malloc(sizeof(Product));
        fscanf(fp,"%d",&newPtr->id);
        fscanf(fp," %[^\n]s",newPtr->TVname);
        newPtr->next = NULL;

        if (startPtr == NULL || strcmp(newPtr->TVname, startPtr->TVname) < 0)
        {
            // If the list is empty or the new TV's name comes before the first TV's name in the list,
            // insert the new TV at the beginning of the list
            newPtr->next = startPtr;
            startPtr = newPtr;
        }
        else
        {
            // Otherwise, find the position in the list where the new TV should be inserted
            currentPtr = startPtr;
            while (currentPtr->next != NULL && strcmp(newPtr->TVname, currentPtr->next->TVname) > 0)
            {
                // Traverse the list until we find the correct position to insert the new TV
                currentPtr = currentPtr->next;
            }
            // Insert the new TV into the list at the correct position
            newPtr->next = currentPtr->next;
            currentPtr->next = newPtr;
        }
    }
    // Close the file
    fclose(fp);
    return startPtr;
}

void addTV(ProductPtr *startPtr) 
{
    ProductPtr newPtr, currentPtr, previousPtr; 

    // allocate memory for new product
    newPtr = (Product*)malloc(sizeof(Product));

    printf("------------------------------------------------------------------------\n");
    printf("Enter a new TV details:\n");
    printf("ID: ");
    scanf("%d", &newPtr->id);
    getchar();
    printf("Product Name: ");
    scanf(" %[^\n]s",newPtr->TVname);
    newPtr->next = NULL;

    currentPtr = *startPtr;
    previousPtr = NULL;

    // find the correct position to insert new product in alphabetical order
    while (currentPtr != NULL)
    {
        if(strcmp(newPtr->TVname, currentPtr->TVname) > 0)
        {
            previousPtr = currentPtr;
            currentPtr = currentPtr->next;
        }
        // otherwise, insert the new product between previous and current
        else if (strcmp(newPtr->TVname, currentPtr->TVname) <= 0)
        {
            newPtr->next = currentPtr; 
            previousPtr->next = newPtr;
            break;
        }
    }
    // if the new product is the first in the list, update the start pointer
    if (previousPtr == NULL)
    {
        newPtr->next = *startPtr;
        *startPtr = newPtr;
    }
    printf("------------------------------------------------------------------------\n");
    printf("The new TV has been added successfully!\n");
}



void queue_nextOrder_check(OrderPtr headPtr, OrderPtr tailPtr)
{
    if (headPtr == NULL) 
    {
        printf("------------------------------------------------------------------------\n");
        printf("There is no order at the moment.\n");
    } 
    else 
    {
        printf("------------------------------------------------------------------------\n");
        printf("Next order information is:\n");

        printf("%d\t%s\n", 
        headPtr->id,
        headPtr->TVname);
    }
}


void displayOrder(OrderPtr headPtr, OrderPtr tailPtr)
{
    if (headPtr == NULL) 
    {
        printf("------------------------------------------------------------------------\n");
        printf("There is no order at the moment.\n");
    } 
    else 
    {
        printf("------------------------------------------------------------------------\n");
        printf("Order information is:\n");
        OrderPtr current = headPtr;
        while (current != NULL)
        {
            printf("%d\t%s\n", 
            current->id,
            current->TVname);
            current = current->next;
        }
    }
}

void add_order(ProductPtr startPtr, OrderPtr *headPtr, OrderPtr *tailPtr) 
{
    OrderPtr newOrder = (Order*)malloc(sizeof(Order));

    printf("------------------------------------------------------------------------\n");
    printf("Enter new order details:\n");
    printf("ID: ");
    scanf("%d", &newOrder->id);
    printf("Product Name: ");
    scanf(" %[^\n]s", newOrder->TVname);

    newOrder->next = NULL;

    ProductPtr currentPtr = startPtr;
    while (currentPtr != NULL) 
    {
        if ((strcmp(newOrder->TVname, currentPtr->TVname) == 0)&&(currentPtr->id == newOrder->id)) 
        {
            if (*headPtr == NULL) 
            {
                *headPtr = newOrder;
                *tailPtr = newOrder;
            } 
            else 
            {
                (*tailPtr)->next = newOrder;
                *tailPtr = newOrder;
            }
            printf("------------------------------------------------------------------------\n");
            printf("The new order has been added successfully!\n");
            return;
        }
        currentPtr = currentPtr->next;
    }
    printf("------------------------------------------------------------------------\n");
    printf("The product is not in stock.\n");
}

//function 6:
void process_order(StackPtr *newest, ProductPtr *startPtr, OrderPtr *headPtr, OrderPtr *tailPtr)
{
    // Move the head pointer to the next order
    OrderPtr tempPtr = *headPtr;
    *headPtr = (*headPtr)->next;

    if (*startPtr == NULL)
    {
        printf("------------------------------------------------------------------------\n");
        printf("There is no order to process at the moment.\n");
        return;
    }
    // If the queue is empty
    if (*headPtr == NULL)
    {
        *tailPtr = NULL;
    }

    ProductPtr currentPtr = *startPtr;
    StackPtr lastOrder = (Stack*)malloc(sizeof(Stack));
    lastOrder->next = *newest;
    *newest = lastOrder;

    while (currentPtr != NULL)
    {
        if ((strcmp(currentPtr->TVname, tempPtr->TVname) == 0) && (tempPtr->id == currentPtr->id))
        {
            lastOrder->id = currentPtr->id;
            strcpy(lastOrder->TVname, currentPtr->TVname);
            break;
        }
        currentPtr = currentPtr->next;
    }

    // Remove the TV from the linked list
    if (currentPtr == *startPtr)
    {
        // If the current TV node is the first node, update the startPtr to point to the next node
        *startPtr = (*startPtr)->next;
    }
    else
    {
        // If the current TV node is not the first node,
        // traverse the linked list to find the previous node

        // Start with the first node as the previous node
        ProductPtr previousPtr = *startPtr;

        // Traverse the linked list until the next node of the previous node is the current node
        while (previousPtr->next != currentPtr)
        {
            previousPtr = previousPtr->next;
        }
        // Update the next pointer of the previous node to skip over the current node
        previousPtr->next = currentPtr->next;
    }
    free(tempPtr);
    printf("------------------------------------------------------------------------\n");
    printf("The next order has been proceed.\n");
}

//function 7:
void cancel_order(StackPtr *newest, ProductPtr *startPtr)
{
    StackPtr lastOrder = *newest;

    ProductPtr currentPtr = *startPtr;
    ProductPtr previousPtr = NULL;

    // Find the correct position to insert the new product in alphabetical order
    while (currentPtr != NULL)
    {
        if (strcmp(lastOrder->TVname, currentPtr->TVname) > 0)
        {
            previousPtr = currentPtr;
            currentPtr = currentPtr->next;
        }
        else if (strcmp(lastOrder->TVname, currentPtr->TVname) <= 0)
        {
            // Insert the new product between previous and current
            lastOrder->next = currentPtr;
            if (previousPtr != NULL)
                previousPtr->next = lastOrder;
            else
                *startPtr = lastOrder; // New product is the first in the list
            break;
        }
    }

    // If the new product is the last in the list, update the *newest pointer
    if (currentPtr == NULL)
    {
        lastOrder->next = NULL;
        *newest = lastOrder;
    }
    printf("------------------------------------------------------------------------\n");
    printf("The last order has been canceled.\n");
}

void display_Order(StackPtr *newest)
{
    if (*newest == NULL)
    {
        printf("------------------------------------------------------------------------\n");
        printf("There is no order to process at the moment.\n");
    } 
    else 
    {
        printf("------------------------------------------------------------------------\n");
        printf("Information of last order is:\n");
        printf("%d\t%s\n", 
        (*newest)->id,
        (*newest)->TVname);

    }
}

void updateFile(ProductPtr startPtr) 
{
    // Open the file in append mode
    FILE* fp = fopen("TVs.txt", "w");
    if (fp == NULL) 
    {
        printf("Error opening file to update.\n");
        return;
    }

    ProductPtr currentPtr = startPtr;
    while (currentPtr != NULL) 
    {
        fprintf(fp, "%d\t%s\n", currentPtr->id, currentPtr->TVname);
        currentPtr = currentPtr->next;
    }

    // Close the file
    fclose(fp);

    printf("------------------------------------------------------------------------\n");
    printf("Update File Completed.\n");
}


//this function 1: is used to display TV list to the screen
void displayFile(ProductPtr startPtr)
{
    //print out the TV list
    printf("------------------------------------------------------------------------\n");
    printf("ID\tProduct Name \n");
    printf("------------------------------------------------------------------------\n");
	// loop through the list and print each node
	while (startPtr != NULL)
	{
		printf("%d\t%s \n",
		startPtr->id,
		startPtr->TVname);
	
		startPtr = startPtr->next;
	}
}

//this function is created to display the instruction to the user
int menu()
{
    int option;    
    //display the menu
	printf("------------------------------------------------------------------------\n");
	printf("\t\t\tWelcome to the TV Store\n");
    printf("------------------------------------------------------------------------\n");
    printf("(1) Display the current stock of TVs \n");
    printf("(2) Add a new TV to stock \n");
    printf("(3) Display next order information \n");
    printf("(4) Display all orders \n");
    printf("(5) Add order to queue \n");
    printf("(6) Process the next order \n");
    printf("(7) Cancel last order \n");
    printf("(8) Display info of last order \n");
    printf("(9) Update TV file \n");
    printf("(10) Quit program \n");
    printf("Select your option: ");
    scanf("%d",&option);
    
    return option; // add this line to return the selected option to the main function
}

//main function to link all of the functions together
void main()
{	
    ProductPtr startPtr = readTVs();
    ProductPtr headPtr = NULL;
    ProductPtr tailPtr = NULL;
    StackPtr newest= NULL;

    int option;
    do
    {
        option = menu();
        if (option == 1)
        {
            displayFile(startPtr);
        }
        else if (option == 2)
        {
            addTV(&startPtr);
        }
        else if (option == 3)
        {
            queue_nextOrder_check(headPtr, tailPtr);
        }
        else if (option == 4)
        {
            displayOrder(headPtr, tailPtr);
        }
        else if (option == 5)
        {
            add_order(startPtr, &headPtr, &tailPtr);
        }
        else if (option == 6)
        {
            process_order(&newest, &startPtr, &headPtr, &tailPtr);
        }
        else if (option == 7)
        {
            cancel_order(&newest, &startPtr);
        }
        else if (option == 8)
        {
            display_Order(&newest);
        }

        else if (option == 9)
        {
            updateFile(startPtr);
        }

        else if (option == 10)
        {
          	printf("------------------------------------------------------------------------\n");
            printf("Exiting the program...\n");
			printf("------------------------------------------------------------------------\n");  
        }
    } while (option != 10);
}

