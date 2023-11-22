/*
Unit Code: COS10007
Unit Name: Developing Techinical Software
Student ID: 103488515
Name: Hai Nam Ngo
Date Created: 5/9/2023
Date Modified: 5/9/2023
Problem: Week 9 Question 4
Problem: Write a complete C++ program with the two alternate functions specified below.
These functions will double the variable count defined in main.
a. Function doubleByValue that passes a copy of count by value, double the copy
and returns the new value.
b. Function doubleByReference that passes count by reference via a reference
parameter, double the original value of count through its alias, i.e. the reference
parameter.
*/

#include <iostream>
using namespace std;

// function prototype (value pass)
int doubleByValue(int);

// function prototype (reference pass)
void doubleByReference(int&);

int doubleByValue(int number)
{
    return number * 2;
}

void doubleByReference(int& numberRef)
{
    numberRef *= 2;
}

int main()
{
    int x, y;
    
    // part a
    cout << "Enter value of x before double: ";
    cin >> x;
    
    cout << "Value returned by doubleByValue: " << doubleByValue(x) << endl;
    cout << "x = " << doubleByValue(x) << " after doubleByValue\n" << endl;
    
    // part b
    cout << "Enter value of y before double: ";
    cin >> y;
    
    doubleByReference(y);
    
    cout << "Value returned by doubleByReference: " << y << endl;
    cout << "y = " << y << " after doubleByReference\n" << endl;
    
    return 0;
}
