#include<iostream>

using namespace std;
int main()
{
int n,i,item,flag=0,r;

cout<<"enter number of elements";
cin>>n;
int a[n];
cout<<"enter array elements";
for(i=0;i<=n-1;i++)
{
cin>>a[i]

}
cout<<"enter item to be found";
cin>>item;
for(i=0;i<=n-1;i++)
{
if(a[i]==item)
{
cout<<item <<"found at"<<i+1;
flag=1;
break;
}

}
if(flag==0)
{
cout<<"item not found";

}

return 0;
}
