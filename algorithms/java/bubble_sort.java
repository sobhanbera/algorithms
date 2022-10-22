import java.util.*;

class BubbleSort {
    public static void main(String[] args) {
        int arr[] = {4, 12, 23, 1, 90, 1243, 98, 24, 1,56, 124};
        bubbleSort(arr);
        System.out.println("Array after sorting is: ");
        for(int i : arr) {
            System.out.print(i + " ");
        }
    }

    public static void bubbleSort(int arr[]) {
        int n = arr.length;
        boolean swapped;
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++) { 
                if (arr[j] > arr[j + 1]) { 
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }
            if (swapped == false)
                break;
        }
    }
}