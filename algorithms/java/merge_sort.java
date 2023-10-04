import java.io.*;
public class MergeSort{
    void merge(int arr[], int l, int m, int r){
        // Your code here
        int[] mix = new int[r-l+1];
        int i = l;
        int j = m+1;
        int k = 0;
        while(i <= m && j <= r) {
            if(arr[i] <= arr[j]) {
                mix[k] = arr[i];
                i++;
            } 
            else {
                mix[k] = arr[j];
                j++;
            }
            k++;
        }
        
        while(i <= m) {
            mix[k] = arr[i];
            i++;
            k++;
        }
        
        while(j <= r) {
            mix[k] = arr[j];
            j++;
            k++;
        }
        
        for(i=0;i<mix.length;i++) {
            arr[l+i] = mix[i];
        }
    }
    
    void mergeSort(int arr[], int l, int r){
        if(r > l) {
            int m = l + (r-l) / 2;
            mergeSort(arr, l, m);
            mergeSort(arr, m+1, r);
            merge(arr, l, m, r);
        }
    }
    
	static void printArray(int arr[]){
        int n = arr.length;
        for (int i = 0; i < n; ++i){
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
 
    public static void main(String args[]){
        int arr[] = { 82, 61, 33, 45, 16, 57 };
        System.out.println("Given array is");
        printArray(arr);
        MergeSort ob = new MergeSort();
        ob.mergeSort(arr, 0, arr.length - 1);
        System.out.println("\nSorted array is");
        printArray(arr);
    }
}
