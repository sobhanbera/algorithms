#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int *array, int size, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int temp = 0;

    if (left < size && array[left] > array[largest]) {
        largest = left;
    }

    if (right < size && array[right] > array[largest]) {
        largest = right;
    }

    if (largest != index) {
        temp = array[index];
        array[index] = array[largest];
        array[largest] = temp;
        heapify(array, size, largest);
    }
}

void heapSort(int *array, int size)
{
    int i = 0;
    int temp = 0;

    for (i = size / 2 - 1; i >= 0; i--) {
        heapify(array, size, i);
    }

    for (i = size - 1; i >= 0; i--) {
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        heapify(array, i, 0);
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
    
    heapSort(array, SIZE);

    printf("Sorted array: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
