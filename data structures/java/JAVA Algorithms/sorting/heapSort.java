import java.util.Scanner;
public class heapSort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0;i<n;i++) arr[i] = sc.nextInt();
        creatHeap(arr,n); //buiulding max heap
        for(int i=n-1;i>0;i--){
            //swapping with last element
            int temp = arr[i];
            arr[i] = arr[0];
            arr[0] = temp;
            heapify(arr,i,0);
        }
        for(int i:arr) System.out.print(i + ",");
        System.out.println();    
        
    }
    //createHeap
    public static void creatHeap(int[] arr,int n){
        for(int i=n/2;i>=0;i--){
            heapify(arr,n,i);
        }
    }
    public static void heapify(int[] arr,int n,int i){
        int maxIdx = i;
        int leftIdx = 2*i + 1;
        int rightIdx = 2*i + 2;
        if(leftIdx < n && arr[maxIdx] < arr[leftIdx]) maxIdx = leftIdx;
        if(rightIdx < n && arr[maxIdx] < arr[rightIdx]) maxIdx = rightIdx;
        if(maxIdx != i){
            int temp = arr[maxIdx];
            arr[maxIdx] = arr[i];
            arr[i] = temp;
            heapify(arr,n,maxIdx);
        }
    }
}
