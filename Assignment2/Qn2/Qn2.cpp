/*
Unit Code: COS10007
Unit Name: Developing Technical Software
Student Name: Hai Nam Ngo
Student id: 103488515
Name of the file: Qn2.cpp
Brief explanation: A C++ program that check if the credit card is valid or not by using Luhn Algorithm.
Input: cardNum( series of number from the credit card)
Output: The system will check if it is valid or not.
Date created: 5/1/2023
Last modified: 5/13/2023
*/

#include <iostream> // allows program to perform input and output
#include <string>
#include <cmath>
using namespace std;

#define SIZE 20

//prototype of the function
int sum1(int cardNum[],int array_size);
int sum2(int cardNum[],int array_size);

int main()
{
    //Step1: Read in credit card number as a series of digits into an array
    int cardNum[SIZE];
    int i=0,number;
    //print out the menu
    cout <<"---------------------------------------------------------\n";
    cout <<"\t\tCredit card checking system\n";
    cout <<"---------------------------------------------------------\n";
    cout <<"Rules:\n(1) Use space between each digit\n(2) Use '-1' to end the series\n(3) Maximum 20 digits\n";
    cout <<"---------------------------------------------------------\n";  
    cout <<"Enter credit card number: ";

    //run the code when the user enters a valid number (below 20)
    while (i < SIZE) 
    {
        cin >> number;
        if (number == -1) 
        {
            break; // stop if user enters -1
        }
        cardNum[i] = number; //copy the number to the array
        i++; //increment the counter
    }

    // Print out the array
    cout << "Your credit card number is:";
    for (int j = 0; j < i; j++) {
        cout << " " << cardNum[j];
    }
    cout <<endl;

    //step 4: calculate check sum
    int checkSum = 0;

    //calculate the check sum
    checkSum = (sum1(cardNum,i) + sum2(cardNum,i)) * 9;
    cout << "The credit card check sum is: " << checkSum << endl;
    
    if (checkSum % 10 == 0) // if checkSum has the last digit equal to 0
    {
        cout <<"---------------------------------------------------------\n";  
        cout << "Your credit card number is valid" << endl;
    }
    else
    {
        cout <<"---------------------------------------------------------\n";  
        cout << "Your credit card number is invalid" << endl;
    }
    return 0;
}

//step 2: find sum1
int sum1(int cardNum[],int array_size)
{
    int j,doubled;
    int sum1=0;
    //start from the first second-digit, end continue to run to find other second-digits, except the last digit in the series)
    cout <<"The number for sum1 is:";
    for(j=1; j<array_size;j+=2)
    {
        cout << cardNum[j] << " ";
    }
    cout << endl;
    for (j = 1; j < array_size-1;j+=2)
    {
        doubled = cardNum[j]; //copy the first digit to doubled
        doubled*=2; //multiply  by 2

        if (doubled >= 10) //if the number has two digits
        {
            sum1 += (doubled / 10) + (doubled % 10); //sum will be the sum of the two digits
        }
        else
        {
            sum1+=doubled;
        }
    }

    cout << "sum1 = " << sum1 << endl;
    return sum1; //return the sum1 
}

//step 3: find sum2
int sum2(int cardNum[],int array_size)
{
    int j;
    int sum2=0;

    for(j=0;j < array_size-1;j+=2)
    {
        sum2 += cardNum[j]; //sum will be the sum of every other digits except the last one
    }

    cout << "sum2 = " << sum2 << endl;
    return sum2;
}





