#include <iostream>
using namespace std;

int countNegative(int array[], int arraySize)
{
    int count = 0;
    cout << "Insert the elements for the array: ";
    for (int i = 0; i < arraySize; i++)
    {
        cin >> array[i];

        if (array[i] < 0)
        {
            count += 1;
        }
    }
    cout << "Number of negative elements is: ";
    return count;
}

int countNegative(float array2[], int arraySize)
{
    int count = 0;
    cout << "Insert the elements for the array: ";
    for (int i = 0; i < arraySize; i++)
    {
        cin >> array2[i];

        if (array2[i] < 0)
        {
            count += 1;
        }
    }
    cout << "Number of negative elements is: ";
    return count;
}

int main()
{
    int SIZE;
    cout << "Enter the number of elements in the array: ";
    cin >> SIZE;

    int array[SIZE];
    float array2[SIZE];

    cout << countNegative(array, SIZE) << endl;
    cout << countNegative(array2, SIZE) << endl;
    return 0;
}
