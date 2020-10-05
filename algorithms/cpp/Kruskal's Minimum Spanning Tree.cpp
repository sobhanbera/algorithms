#include "bits/stdc++.h"
using namespace std;
const int maxn = 100005;

// DSU 
int par[maxn] , siize[maxn];
int find_par(int x)
{
    if(x==par[x])
        return x;
    return par[x] = find_par(par[x]);
}
void uni(int x,int y)
{
    int px = find_par(x) , py = find_par(y);
    if(px!=py)
    {
        if(siize[px]>siize[py])
            swap(px,py);
        par[px] = py;
        siize[py] += siize[px];
        siize[px] = 0;
    }
}
 
// structure of an edge.
int n,m;
struct edge
{
    int a,b,w;
};

// Comparator function for sorting the edges.
bool comp(edge A,edge B)
{
    if(A.w < B.w)
        return 1;
    return 0;
}

edge ar[maxn];

signed main()
{
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n,m;
    cin>>n>>m;

    // Initialize DSU.
    for(int i=1; i<=n; i++)
        par[i] = i ,siize[i] = 1;

    for(int i=0; i<m; i++)
    {
        int a,b,w;
        cin>>ar[i].a >>ar[i].b >>ar[i].w;
    }

    // sum - weight of MST.
    int sum=0 ;
    sort(ar,ar+m,comp);
    for(int i=0; i<m; i++)
    {
        int pa = find_par(ar[i].a);
        int pb = find_par(ar[i].b);
        if(pa!=pb)
        {   
            sum += ar[i].w;
            uni(ar[i].a ,ar[i].b);
        }
    }
    cout<<sum<<endl;
    return 0;
}
