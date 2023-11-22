/*
Unit Code: COS10007
Unit Name: Developing Technical Software
Student Name: Hai Nam Ngo
Student id: 103488515
Name of the file: Qn3.cpp
Brief explanation: A C++ program that check if the credit card is valid or not by using Luhn Algorithm.
Input: cardNum( series of number from the credit card)
Output: The system will check if it is valid or not.
Date created: 5/1/2023
Last modified: 5/13/2023
*/

#include <iostream>
using namespace std;

#include "comparison.h" // include definition of function template maximum
int main()
{
    int int1, int2;
    char char1, char2;
    float float1, float2;
    cout << "Input two integer values (with space): ";
        cin >> int1 >> int2;
        // display the result
        cout << "The larger integer value is: "<< maximum( int1, int2)<< endl;
        cout<<"The smaller integer value is: "<< minimum( int1, int2)<< endl;

    cout << "Input two character values (with space): ";
        cin >> char1 >> char2;
        // display the result
        cout << "The larger character value is: "<< maximum( char1, char2)<< endl;
        cout<<"The smaller character value is: "<< minimum( char1, char2)<< endl;

    cout << "Input two floating-point values (with space): ";
        cin >> float1 >> float2;
        // display the result
        cout << "The larger floating-point value is: "<< maximum( float1, float2)<< endl;
        cout<<"The smaller floating-point value is: "<< minimum( float1, float2)<< endl;
}
