#include <stdio.h>
#include <stdlib.h>

void countingSort(int *array, int n)
{
    // Find the maximum element in the array.
    int max = array[0];
    for (int i = 1; i < n; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    // Create an auxiliary array of size max + 1.
    int *count = malloc((max + 1) * sizeof(int));
    for (int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    // Iterate over the input array and increment the corresponding element in the auxiliary array.
    for (int i = 0; i < n; i++)
    {
        count[array[i]]++;
    }

    // Iterate over the auxiliary array and update the input array accordingly.
    int i = 0;
    int j = 0;
    while (j <= max)
    {
        if (count[j] > 0)
        {
            array[i] = j;
            i++;
            count[j]--;
        }
        else
        {
            j++;
        }
    }

    free(count);
}

int main()
{
    // Ask the user for the number of elements.
    int n;
    printf("Enter total number of elements: ");
    scanf("%d", &n);

    // Allocate memory for the array.
    int *array = malloc(n * sizeof(int));

    // Ask the user for the elements.
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    // Sort the array using Counting Sort.
    countingSort(array, n);

    // Print the sorted array.
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free the memory allocated for the array.
    free(array);

    return 0;
}

// end of Main function

/*Sample Input Output
Enter total number of elements :: 10
Enter elements : 36 432 43 44 57 63  94 3 5 6

Sorted Array in ascending order is :
    3    5    6    36     43     44     57     63     94     432
*/
