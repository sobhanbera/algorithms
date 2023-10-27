import java.util.Scanner;

public class SelectionSort {

    /**
     * This method performs the selection sort algorithm on the input array.
     *
     * @param arr The array to be sorted.
     */
    public static void selectionSort(int[] arr) {
        int n = arr.length;

        for (int i = 0; i < n - 1; i++) {
            // Assume the current index has the minimum value
            int minIndex = i;

            for (int j = i + 1; j < n; j++) {
                // If a smaller element is found, update minIndex
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }

            // Swap the found minimum element with the element at index i
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
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

        // Perform Selection Sort
        selectionSort(arr);

        // Output the sorted array
        System.out.println("Sorted array:");
        for (int i : arr) {
            System.out.print(i + " ");
        }
    }
}
/*

 Enter the size of the array: 6
Enter the elements of the array:
12 5 7 3 9 2

Sorted array:
2 3 5 7 9 12

 */