#include <bits/stdc++.h>
using namespace std;

//funtion to search any element present in the given array.
bool binarySearch(int arr[], int n, int x) {
    //two pointers left and right which would come closer to the element to find.
    int left = 0, right = n-1, middle;

    while(left <= right) {
        //to check only the middle indexed element in the given array.
        middle = (left + right) / 2;
        if(arr[middle] == x) {
            return true;
        }else if(arr[middle] > x) {
            right = middle - 1;
        }else {
            left = middle + 1;
        }
    }
    //return false finally when there is no element x present in the given array.
    return false;
}

int main() {
    //Example array...
    int arr[] = {5, 10, 30, 37, 99, 239, 274, 590, 874, 1023};
    int n = sizeof(arr) / sizeof(arr[0]), q;
    //asking the user to provide the number of queries to do in the above array.
    cout << "Enter number of queries: ";
    cin >> q;
    for(int i = 0; i < q; ++i) {
        int x;
        //element input by user
        cout << "Enter number to search: ";
        cin >> x;
        //checking wheter it is present in the array-arr
        if(binarySearch(arr, n, x)) {
            cout << x << " is present in the array.\n";
        }else {
            cout << x << " is not present in the array.\n";
        }
    }
    return 0;
}