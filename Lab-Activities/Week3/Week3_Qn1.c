/*
Unit Code: COS10007
Unit Name: Developing Techinical Software
Student ID: 103488515
Name: Hai Nam Ngo
Date Created: 3/24/2023
Date Modified: 3/24/2023
Problem: Week 3 Question 1
Problem Description: inserts 10 random integers between 0 and 50 in order in a
linked list. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void insert(Node** head, int data) 
{
    // Allocate memory for a new node and set its data value
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    // If the list is empty or the new node's data is less than the head's data, insert at the beginning
    if (*head == NULL || data < (*head)->data) 
	{
        new_node->next = *head;
        *head = new_node;
    } 
	else 
	{ // Otherwise, find the correct position to insert the new node and update pointers accordingly
        Node* current = *head;
        while (current->next != NULL && current->next->data < data) 
		{
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

float average(Node* head) 
{
    // Traverse the list, keeping track of the sum and count of elements
    int sum = 0, count = 0;
    while (head != NULL) 
	{
        sum += head->data;
        count++;
        head = head->next;
    }
    // Calculate and return the average as a float
    return (float) sum / count;
}

int main() 
{
    srand(time(NULL)); // Seed the random number generator with the current time

    Node* head = NULL; // Initialize the head pointer to NULL
    for (int i = 0; i < 10; i++) 
	{
        int data = rand() % 51; // Generate a random integer between 0 and 50
        insert(&head, data); // Insert the new value in order into the linked list
    }

    printf("List elements: ");
    Node* current = head;
    while (current != NULL) 
	{ // Traverse the list and print each element
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    printf("Average: %.2f\n", average(head)); // Calculate and print the average of the list

    return 0; 
}

