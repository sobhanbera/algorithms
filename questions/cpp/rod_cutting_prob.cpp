#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"enter the length of rod\n";
    cin>>n;
    int price[n]={0},t;
    cout<<"Enter the no of prices given\n";
    cin>>t;
    while(t--)
    {
        cout<<"Enter length and price\n";
        int a,b;
        cin>>a>>b;
        price[a-1]=b;
    }
    int val[n+1]={0};
    for(int i=1;i<=n;i++)
    {
        int value=INT_MIN;
        for(int j=0;j<i;j++)
            value=max(value,price[j]+val[i-j-1]);
        val[i]=value;
        cout<<" Best Prices till len="<<i<<" -\t ";
        for(int k=1;k<=n;k++)
            cout<<val[k]<<" ";
        cout<<endl;
    }
    cout<<val[n];

}
