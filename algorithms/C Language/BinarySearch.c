// BINARY SEARCH
#include <stdio.h>
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
    int n, i, item;
    printf("\nEnter the no of array elements: ");
    scanf("%d", &n);
    int a[n];
    printf("\nEnter the array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("\nEnter the item to be searched: ");
    scanf("%d", &item);

    int result = BinarySearch(a, n, item);
    if (result == -1)
    {
        printf("\nElement not found\n");
    }
    else
    {
        printf("\nElement is found at index: %d\n", result);
    }
    return 0;
}

/*
Output: Test 1:
Enter the no of array elements: 5

Enter the array elements: 3 4 8 9 12

Enter the item to be searched: 6

Element not found

Test 2:
Enter the no of array elements: 6

Enter the array elements: 1 4 6 9 23 45

Enter the item to be searched: 6

Element is found at index: 2

*/