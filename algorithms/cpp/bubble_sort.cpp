#include <iostream>
using namespace std;

void bubSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    for (int j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(arr[j], arr[j+1]);
}

int main()
{
    int n;
    cin>>n;

    int*arr=new int[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    bubSort(arr,n);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    
    return 0;
}

