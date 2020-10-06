import java.util.*;

// Java implementation of Insertion Sort
public class InsertionSort{
    // The method for insertion sort implementation
    public static void insertionSort(int[] arr, int n){
        for(int i=1; i<n; i++) {
            int key = arr[i];
            int j = i-1;
            
            while(j>=0 && arr[j] > key) {
                arr[j+1] = arr[j];
                j = j-1;
            }
            arr[j+1] = key;
        }
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n; // Number of array elements
        System.out.print("Enter the number of array elements:\t");
        n = in.nextInt();
        
        // Define and input array elements
        int[] arr = new int[n];
        System.out.println("Enter the array elements:");
        for(int i=0; i<n; i++) {
            arr[i] = in.nextInt();
        }
        
        insertionSort(arr, n);
        
        // Print the final array
        System.out.println("Sorted array elements are:");
        for(int i=0; i<n; i++) {
            System.out.println(arr[i]);
        }
        
    }
}