// Counting sort in C++ programming

#include <iostream>
using namespace std;

void countSort(int array[], int size) 
{

    /* The size of count must be at least the (max+1) but
        we cannot assign declare it as int count(max+1) in C++ as
        it does not support dynamic memory allocation.
        So, its size is provided statically. */
    
    int output[1000000]; // taking the numerical limit to be 10^6
    int count[1000000]; // taking the numerical limit to be 10^6
    int max = array[0];

    // Find the largest element of the array
    for (int i = 1; i < size; i++) 
    {
        if (array[i] > max)
            max = array[i];
    }

    // Initialize count array with all zeros.
    for (int i = 0; i <= max; ++i) 
        count[i] = 0;

    // Store the count of each element
    for (int i = 0; i < size; i++) 
        count[array[i]]++;

    // Store the cummulative count of each array
    for (int i = 1; i <= max; i++) 
        count[i] += count[i - 1];

    // Find the index of each element of the original array in count array, and
    // place the elements in output array
    for (int i = size - 1; i >= 0; i--) 
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // Copy the sorted elements into original array
    for (int i = 0; i < size; i++) 
        array[i] = output[i];

}

// Function to print an array
void printArray(int array[], int size) 
{

    for (int i = 0; i < size; i++)
        cout << array[i] << " ";

    cout << endl;

}

// Driver code
int main() 
{
    // Creating a Sample Array in C++
    int array[] = {4, 32, 2, 83, 3, 321, 145556};

    // Finding the size of the array
    int n = sizeof(array) / sizeof(array[0]);

    // Calling the Counting Sort Algorithm function
    countSort(array, n);

    // Printing the Sorted Array
    printArray(array, n);

}
