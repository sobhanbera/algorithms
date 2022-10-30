#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void countingSort(int *array, int size)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int max = 0;
    int *count = NULL;

    for (i = 0; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    count = (int *)calloc(max + 1, sizeof(int));

    for (i = 0; i < size; i++) {
        count[array[i]]++;
    }

    for (i = 0; i <= max; i++) {
        for (j = 0; j < count[i]; j++) {
            array[k++] = i;
        }
    }

    free(count);
}

int main(void)
{
    #define SIZE 10

    int array[SIZE] = {0};
    int i = 0;

    srand(time(NULL));

    for (i = 0; i < SIZE; i++) {
        array[i] = rand() % 100;
    }

    printf("Unsorted array: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    countingSort(array, SIZE);

    printf("Sorted array: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
