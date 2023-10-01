#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSort(vector<int>& arr) {
    int max = *max_element(arr.begin(), arr.end()); // Find the maximum element in the array

    vector<int> count(max + 1, 0); // Create a count array to store the count of each element
    vector<int> output(arr.size());

    // Count the occurrences of each element in the input array
    for (int i = 0; i < arr.size(); ++i) {
        count[arr[i]]++;
    }

    // Calculate the cumulative count
    for (int i = 1; i <= max; ++i) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = arr.size() - 1; i >= 0; --i) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = output[i];
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " positive elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    countingSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
