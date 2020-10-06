#include<bits/stdc++.h>

using namespace std;

// Function of sorting in quick sort
void quickSort(int arr[], int left, int right) {
	int pivot, index_left = left, index_right = right, temp;
	pivot = (left);
	if(left<right) {
		while(index_left < index_right) {
			
			while(arr[index_left]<=arr[pivot] && index_left<=right){
				index_left++;
			}
			
			while(arr[index_right]>arr[pivot] && index_right>=left){
				index_right--;
			}
			
			if(index_left < index_right) {
				temp = arr[index_left];
				arr[index_left] = arr[index_right];
				arr[index_right] = temp;
			}
		}
		temp = arr[pivot];
		arr[pivot] = arr[index_right];
		arr[index_right] = temp;
		quickSort(arr, left, index_right-1);
		quickSort(arr, index_right+1, right);
	}
}

int main() {
	int n;
	cout<<"Enter the number of array elements:\t";
	cin>>n;
	
	int arr[n];
	cout<<"Enter the array elements:"<<endl;
	for(int i=0; i<n; i++) {
		cin>>arr[i];
	}
	
	quickSort(arr, 0, n-1);
	
	cout<<"The sorted array elements are:"<<endl;
	for(int i=0; i<n; i++)
		cout<<arr[i]<<endl;
}
