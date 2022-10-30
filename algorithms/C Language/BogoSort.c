#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isSorted(int *array, int size)
{
    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            return 0;
        }
    }
    return 1;
}

void shuffle(int *array, int size)
{
    int i = 0;
    int temp = 0;
    int randomIndex = 0;

    for (i = 0; i < size; i++) {
        randomIndex = rand() % size;
        temp = array[i];
        array[i] = array[randomIndex];
        array[randomIndex] = temp;
    }
}

void bogoSort(int *array, int size)
{
    while (!isSorted(array, size)) {
        shuffle(array, size);
    }
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
    
    bogoSort(array, SIZE);

    printf("Sorted array: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
