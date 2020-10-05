#include <iostream>
using namespace std;

void selSort(int arr[], int n)
{
    int k;
    for (int i = 0; i < n-1; i++)
    {
        k = i;
        for (int j = i+1; j < n; j++)
        if (arr[j] < arr[k])
            k = j;
        swap(arr[k],arr[i]);
    }
}

int main()
{
    int n;
    cin>>n;

    int*arr=new int[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    selSort(arr,n);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    
    return 0;
}

