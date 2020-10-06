#include <bits/stdc++.h>
using namespace std;
#define lld long long int

lld n,w;
lld wt[101],val[101],dp[100001][101];

lld min(lld a,lld b)
{
    if(a<b)
    return a;
    else
    return b;
}
lld fun(lld sval,lld i)
{
    if(sval<=0)                       //Base Case
    return 0;
    if(i==n+1)
    return 1e9+1;
    if(dp[sval][i]!=-1)               //if it is already available then return
    return dp[sval][i];
    else                              //recurrence relation
    return dp[sval][i]=min(fun(sval,i+1),wt[i]+fun(sval-val[i],i+1));
}
int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    t=1;
    while(t--)
    {
        lld sum=0,r,mval=INT_MAX;
        cin>>n>>w;
        for(int i=1;i<=n;i++)
        {
            cin>>wt[i]>>val[i];
            sum+=val[i];
        }
        memset(dp,-1,sizeof(dp));
        for(r=sum;r>=0;r--)         // Iterating through all possible values
        {
            cout<<"For sum="<<r<<" value is "<<fun(r,1)<<"\n";
            if(fun(r,1)<=w)             // to find the the largest value that can
            {                           // be represented by the given weights
                cout<<r;
                break;
            }
        }

    }
}
/*
3
10
3 7
8 8
6 4
*/
