#include <bits/stdc++.h>
using namespace std;

#define lld long long int
int mat[8][8];
int r[]={2, 1, -1, -2, -2, -1,  1,  2};
int c[]={1, 2,  2,  1, -1, -2, -2, -1};
//set <int> l_diagonal;
//set <int> r_diagonal;
int knight(int x,int y,int cnt)
{
    mat[x][y]=cnt;
    if(cnt==64)
    return 1;
    for(int i=0;i<8;i++)
    {
        int a=x+r[i];
        int b=y+c[i];
        if(a>=0&&a<8&&b>=0&&b<8&&mat[a][b]==-1)
        {
            if(knight(a,b,cnt+1))
            return 1;
            else
            mat[a][b]=-1;
        }
    }
    return 0;
}
int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //memset(mat,-1,sizeof(mat));
    for(int i=0;i<8;i++)
    for(int j=0;j<8;j++)
    mat[i][j]=-1;
    if(knight(0,0,1))
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        cout<<mat[i][j]<<"  ";
        cout<<"\n";
    }
    else
    cout<<"NO\n";
}
