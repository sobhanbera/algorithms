#include<bits/stdc++.h>
using namespace std;

void printParenthesis(int i, int j, int n, int *bracket, char &name)
{
    if(i==j)
    {
        cout<<name++;
        return;
    }
    cout<<"(";
    printParenthesis(i, *((bracket+i*n)+j), n,bracket, name);
    printParenthesis(*((bracket+i*n)+j) + 1, j, n, bracket, name);
    cout<<")";
}
void matrixChainOrder(int p[], int n)
{
	int m[n][n];
	int bracket[n][n];

	for(int i=1;i<n;i++)
        for(int j=0;j<n;j++)
		m[i][j] = 0;

	for(int len=2;len<n;len++)
	{
		for(int i=1;i<n-len+1;i++)
		{
		    int j=i+len-1;
			m[i][j]=INT_MAX;
			for(int k=i; k<=j-1; k++)
			{
				int q=m[i][k]+m[k+1][j]+ p[i-1]*p[k]*p[j];
				if (q<m[i][j])
				{
					m[i][j]=q;
                    bracket[i][j]=k;
				}
			}
		}
		cout<<"For length="<<len<<"\n";
		for(int i=1;i<n;i++)
        {
            for(int j=1;j<n;j++)
                cout<<m[i][j]<<"\t";
            cout<<"\n";
        }
        cout<<"\n\n";
    }
	char name='A';
    cout<<"Optimal matrix chain multiplication is ";
	printParenthesis(1, n-1, n, (int *)bracket, name);
	cout<<"\nNo of multiplications are "<<m[1][n-1];
}
int main()
{
	int n;
	cout<<"Enter no of matrix\n";
	cin>>n;
	cout<<"Enter the values\n";
	int arr[++n];
	for(int i=0;i<n;i++)
        cin>>arr[i];
	matrixChainOrder(arr, n);
	return 0;
}
