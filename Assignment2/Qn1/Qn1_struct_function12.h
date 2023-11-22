/*
Unit Code: COS10007
Unit Name: Developing Technical Software
Student Name: Hai Nam Ngo
Student ID: 103488515
Name of the file: Qn1_struct_function12.h
Brief explanation: include libraries, info structure, and function prototypes for displayFile and Sorting Techniques.
Input: None
Output: None
Date created: 5/1/2023
Last modified: 5/9/2023
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10

struct info
{
    char player[10];
    int age;
    int rank;
    double score;
    struct info *next;
};

//prototype for function 1
int displayFile(struct info info[], int arrayLength);

//prototype for function 2
void BubbleSortAsc(struct info info[], int arrayLength);
void BubbleSortDesc(struct info info[], int arrayLength);
void SelectionSortAsc(struct info info[], int arrayLength);
void SelectionSortDesc(struct info info[], int arrayLength);
void sort(struct info info[], int arrayLength);
