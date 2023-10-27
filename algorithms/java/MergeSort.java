import java.util.Scanner;

public class MergeSort {

    public static void merge(int[] arr, int left, int mid, int right) {
        // Calculate the sizes of the two subarrays
        int size1 = mid - left + 1;
        int size2 = right - mid;

        // Create temporary arrays
        int[] leftArray = new int[size1];
        int[] rightArray = new int[size2];

        // Copy data to temporary arrays
        for (int i = 0; i < size1; ++i)
            leftArray[i] = arr[left + i];
        for (int j = 0; j < size2; ++j)
            rightArray[j] = arr[mid + 1 + j];

        // Merge the temporary arrays

        // Initial indexes of first and second subarrays
        int i = 0, j = 0;

        // Initial index of merged subarray array
        int k = left;
        while (i < size1 && j < size2) {
            if (leftArray[i] <= rightArray[j]) {
                arr[k] = leftArray[i];
                i++;
            } else {
                arr[k] = rightArray[j];
                j++;
            }
            k++;
        }

        // Copy remaining elements of leftArray[], if any
        while (i < size1) {
            arr[k] = leftArray[i];
            i++;
            k++;
        }

        // Copy remaining elements of rightArray[], if any
        while (j < size2) {
            arr[k] = rightArray[j];
            j++;
            k++;
        }
    }

   
    public static void mergeSort(int[] arr, int left, int right) {
        if (left < right) {
            // Find the middle point
            int mid = (left + right) / 2;

            // Recursive calls for left and right subarrays
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            // Merge the sorted subarrays
            merge(arr, left, mid, right);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input prompt for array size
        System.out.print("Enter the size of the array: ");
        int size = scanner.nextInt();

        // Input prompt for array elements
        System.out.println("Enter the elements of the array:");
        int[] arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = scanner.nextInt();
        }

        // Perform Merge Sort
        mergeSort(arr, 0, size - 1);

        // Output the sorted array
        System.out.println("Sorted array:");
        for (int i : arr) {
            System.out.print(i + " ");
        }
    }
}


/*
Enter the size of the array: 5
Enter the elements of the array:
12 5 7 3 9
Sorted array:
3 5 7 9 12

 */