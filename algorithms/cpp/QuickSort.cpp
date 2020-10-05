#include<iostream>
using namespace std;

//swap function
void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 

/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
	array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high];  
	int i = (low - 1);  

	for (int j = low; j <= high- 1; j++) 
	{ 
		 
		if (arr[j] < pivot) 
		{ 
			i++;  
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 

/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		
		int pi = partition(arr, low, high); 

		
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		cout << "\n" << arr[i];  
} 

//Driver code 
int main() 
{ 
	int arr[100], n;
    cout << "\nEnter size of array\t";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
	printArray(arr, n); 
	quickSort(arr, 0, n-1); 
	cout << "\nSorted array by Quick sort: \n"; 
	printArray(arr, n); 
	return 0; 
} 
