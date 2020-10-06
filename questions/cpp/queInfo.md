//Add any competitive programming question with solution in this folder you want in C++ language. for more info read the readme in the main repository directory.
//Please add some comments to understand what your code is doing.
//Thanks...

//Question:

//You are given an integer array and you are asked to find the smallest (minimum) element of the array. This program asks the user to enter the value of n (number of elements) and //then user is asked to enter the array elements. The program then finds the smallest element in the entered elements.

//Solution:

#include <iostream>
using namespace std;
int findSmallestElement(int arr[], int n){
   /* We are assigning the first array element to
    * the temp variable and then we are comparing
    * all the array elements with the temp inside
    * loop and if the element is smaller than temp
    * then the temp value is replaced by that. This
    * way we always have the smallest value in temp.
    * Finally we are returning temp.
    */
   int temp = arr[0];
   for(int i=0; i<n; i++) {
      if(temp>arr[i]) {
         temp=arr[i];
      }
   }
   return temp;
}
int main() {
   int n;
   cout<<"Enter the size of array: ";
   cin>>n; int arr[n-1];
   cout<<"Enter array elements: ";
   for(int i=0; i<n; i++){
      cin>>arr[i];
   }
   int smallest = findSmallestElement(arr, n);
   cout<<"Smallest Element is: "<<smallest;
   return 0;
}
  
  //Output :
/*  Enter the size of array: 5
Enter array elements: 11
9
18
88
101
Smallest Element is: 9 */
