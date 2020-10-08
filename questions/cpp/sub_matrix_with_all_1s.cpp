#include<bits/stdc++.h>
using namespace std;

int fun(int arr[][125],int r,int c)
{
    int sum[r][c],mx=0;
    for(int i=0;i<r;i++)
        sum[i][0]=arr[0][i];
    for(int j=0;j<c;j++)
        sum[0][j]=arr[0][j];
    for(int i=1;i<r;i++)
        for(int j=1;j<c;j++)
        {
            if(arr[i][j]==1)
                sum[i][j]=min(sum[i][j-1],min(sum[i-1][j-1],sum[i-1][j]))+1;
            else
                sum[i][j]=0;
        }
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        if(mx<sum[i][j])
                mx=sum[i][j];

    cout<<"size of sub matrix is "<<mx<<"X"<<mx;


    return 0;
}
int main()
{
    int r,c;
    cout<<"enter no of rows and columns\n";
    cin>>r>>c;
    int arr[r][125];
    cout<<"enter the elements\n";
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        cin>>arr[i][j];
    fun(arr,r,c);
    return 0;
}
