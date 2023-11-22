/*
Unit Code: COS10007
Unit Name: Developing Techinical Software
Student ID: 103488515
Name: Hai Nam Ngo
Date Created: 5/9/2023
Date Modified: 5/9/2023
Problem: Week 9 Question 3
Problem Description: Write a complete program that prompt the user for the radius of a sphere and calculates and prints its volume. Use an inline function sphereVolume that returns the result of the volume
*/

#include <iostream>
#include <cmath>

using namespace std;

inline double sphereVolume(double radius)
{
    return (4.0 / 3.0) * M_PI * pow(radius, 3);
}

int main()
{
    double radius, volume;    
    cout<< "Enter the radius of the sphere: ";
    cin>> radius; 
	
    volume = sphereVolume(radius); 
	
    cout<<"The volume of the sphere is: "<<volume<<endl;   
    return 0;
}