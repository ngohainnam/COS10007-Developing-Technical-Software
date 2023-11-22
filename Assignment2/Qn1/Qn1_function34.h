/*
Unit Code: COS10007
Unit Name: Developing Technical Software
Student Name: Hai Nam Ngo
Student ID: 103488515
Name of the file: Qn1_struct_function12.h
Brief explanation: include function prototypes for searching and and linked list transfer.
Input: None
Output: None
Date created: 5/1/2023
Last modified: 5/9/2023
*/
//prototype for function 3
int linear_search(const char *search_key, struct info info[],int i,int arrayLength);
int binary_search(const char *search_key, struct info info[],int low, int high);
//one prototype function to call the whole 4 functions above
int searching(struct info info[],int i,int low,int high, int arrayLength);

//prototype for function 4
void linked_list(struct info info[],int arrayLength);
