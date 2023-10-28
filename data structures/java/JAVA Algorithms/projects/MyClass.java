/*Shell sort addresses this problem and reduces the number of shifts/swaps by dividing the array into subarrays of intervals (gap) and then applying insertion sort on
the sub-arrays. This process is repeated with reducing interval (gap) size until the gap becomes 0. 
As a result, the number of swaps significantly reduces but at the cost of more number of comparisons.*/


public class MyClass {
  public static void main(String args[]) {
      int arr[] = {4,2,8,4,6,1};
      shellSort(arr);
      for(int i=0;i<arr.length;i++)
          System.out.print(arr[i]+" ");
  }
  public static void shellSort(int arr[])
  {
      int n = arr.length;
      int gap = n/2;
      while(gap>0)
      {
          for(int i=gap;i<n;i++)
          {
              int temp = arr[i];
              int j=i;
              while(j>=gap && arr[j-gap]>temp)
              {
                  arr[j] = arr[j-gap];
                  j -= gap;
              }
              arr[j] = temp;
          }
          gap = gap/2;
      }
  }
}
