#include <iostream>
using namespace std;

// Function for binary search that returns index if element is found otherwise returns -1
int BinarySearch(int array[], int length, int key)
{
    int high = length - 1;
    int low = 0;
    if (low <= high)
    {
        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (key == array[mid])
            {
                return mid;
            }
            else if (key < array[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }

    return -1;
}

int main()
{
    int n;

    cout << "Enter the length of the Array : " << endl;
    cin >> n;
    int A[n];

    cout << "Enter " << n << " elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    cout << "Enter the element to be searched : " << endl;
    int key;
    cin >> key;
    int index = BinarySearch(A, n, key);

    if (index != -1)
    {
        cout << "Element " << key << " found at index " << index << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }

    return 0;
}