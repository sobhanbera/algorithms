#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

//-4%3=-1
        lld n,w;
        lld wt[101],val[101],dp[2][10000001];

lld fun(lld i,lld w)
{
    if(i<=0||w<=0)
    return 0;
    if(dp[i][w]==-1)
    {
        if(wt[i]<=w)
        return dp[i][w]=max(val[i]+fun(i-1,w-wt[i]),fun(i-1,w));
        else
        return dp[i][w]=fun(i-1,w);
    }
    else
    return dp[i][w];

}



int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    //cin>>t;
    t=1;
    while(t--)
    {

        cin>>n>>w;
        for(int i=1;i<=n;i++)
        cin>>wt[i]>>val[i];
        memset(dp,-1,sizeof(dp));
        cout<<fun(n,w);
    }
}

