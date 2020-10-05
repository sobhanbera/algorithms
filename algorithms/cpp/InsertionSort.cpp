#include <iostream>
using namespace std;

void insSort(int arr[], int n)
{
    int k, j;
    for (int i = 1; i < n; i++)
    {
        k = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > k)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = k;
    }
}

int main()
{
    int n;
    cin>>n;

    int*arr=new int[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    insSort(arr,n);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    
    return 0;
}

