#include <bits/stdc++.h>
using namespace std;

bool binarySearch(int arr[], int n, int x) {
    int left = 0, right = n-1, middle;
    while(left <= right) {
        middle = (left + right) / 2;
        if(arr[middle] == x) {
            return true;
        }else if(arr[middle] > x) {
            right = middle - 1;
        }else {
            left = middle + 1;
        }
    }
    return false;
}

int main() {
    //Example array...
    int arr[] = {5, 10, 30, 37, 99, 239, 274, 590, 874, 1023};
    int n = sizeof(arr) / sizeof(arr[0]), q;
    cout << "Enter number of queries: ";
    cin >> q;
    for(int i = 0; i < q; ++i) {
        int x;
        cout << "Enter number to search: ";
        cin >> x;
        if(binarySearch(arr, n, x)) {
            cout << x << " is present in the array.\n";
        }else {
            cout << x << " is not present in the array.\n";
        }
    }
    return 0;
}