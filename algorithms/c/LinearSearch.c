#include<stdio.h>
#include<string.h>

int lsearch(int arr[], int el, int len)
{
    for(int i = 0; i < len; i++)
    {
        if(arr[i] == el)
            return i;
    }

    return -1;
}

int main()
{
    int n, el;

    printf("Enter the length of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of array: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Which element of array you want to search: ");
    scanf("%d", &el);

    printf("Element %d exists at index %d", el, lsearch(arr, el, n));

    return 0;    
}
