/*
a linear search or sequential search is a method for finding an element within a list.
It sequentially checks each element of the list until a match is found or the whole list
has been searched.

It has time complexity of O(n).
____________________
|1|5|8|9|0|10|11|12|  -----> search(9)
                                |
                                |
___________________
|1|5|8|9|0|10|11|12|

 |_______________________is i==9 false next element i=1
   |_____________________is i==9 false next element i=5
     |___________________is i==9 false next element i=8
        |________________is i==9 true return found and break the loop i=9

So it is searching the whole array linearly.

*/

#include <stdio.h>
#include <stdlib.h>

// base utility function to create the array
int *create(int n)
{
    int *a = (int *)malloc(n * sizeof(int));

    printf("\nEnter the elements of Array : ");
    for (int i = 0; i < n; i++)
    {

        scanf("%d", (a + i));
    }

    return a;
}

// linear searching a element
int linear_search(int element, int *a, int n)
{
    // loop intitialisation
    for (int i = 0; i < n; i++)
    {
        /* check if the element is in the array */
        if (*(a + i) == element)
        {
            return i;
        }
    }

    return -1; // return -1 if elements is not found
}

// printing the array function
void display(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {

        printf("%d ", *(a + i));
    }
}

// main function
int main()
{
    int n;

    printf("\nEnter the size of the array : ");
    scanf("%d", &n);

    int *arr = create(n);

    printf("\nThe array is : ");
    display(arr, n);

    int element; // element to search

    printf("\nEnter the element to search : ");
    scanf("%d", &element);

    int flag = linear_search(element, arr, n);

    if (flag == -1)
    {
        printf("\nElement not found\n");
    }
    else
    {
        printf("\nElement found at index : %d\n", flag);
    }
    return 0;
}

/*
Output:
Test 1:
Enter the size of the array : 7

Enter the elements of Array : 1 32 2 56 43 917 23

The array is : 1 32 2 56 43 917 23
Enter the element to search : 56

Element found at index : 3


Test 2:
Enter the size of the array : 7

Enter the elements of Array : 1 32 2 56 43 917 23

The array is : 1 32 2 56 43 917 23
Enter the element to search : 87

Element not found
*/