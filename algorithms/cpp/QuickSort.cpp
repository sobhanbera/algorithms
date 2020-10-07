#include<iostream>
using namespace std;

int partition(int a[],int lb,int ub){
    int pivot = a[lb];
    int start = lb; 
    int end = ub;
    
    while (start<end)
    {
        while(a[start] <= pivot){
            start++;
        }
        while(a[end] > pivot){
            end--;
        }

        if(start < end){
            //- swap(a[start] , a[end])
            int temp = a[start];
            a[start] = a[end];
            a[end] = temp;
        }
    }
    //- swap(a[lb] , a[end]) !
    int anotherTemp = a[lb];
    a[lb] = a[end];
    a[end] = anotherTemp;

    return end; 
}

void quickSort(int a[],int lb,int ub)
{
    int loc;
    if(lb < ub){
        loc = partition(a,lb,ub); 
        quickSort(a,lb,loc-1); 
        quickSort(a,loc+1,ub); 
    } 
}


int main()
{
    int a[10] = {34,75,23,76,12,97,13,45,38,65};
    int n = sizeof(a)/sizeof(int);
    int lb = 0;
    int ub = 9;
    quickSort(a,lb,ub);
    cout<<"Sorted array: \n";
    for (int i = 0; i < n; i++)
    {
        cout<<"["<<a[i]<<"]"<<" ";
    }
    
    return 0;
}

// Best Case : O(n logn)
// Worst Case : O(n^2)
