/***** KADANE'S ALGORITHM TO FIND MAXIMUM SUBARRAY IN ARRAY *****/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];

		// Kadane's Algorithm
		int max_so_far=INT_MIN,max_ending_here=0;

		for(int i=0;i<n;i++)
		{
			max_ending_here=max_ending_here+arr[i];
			if(max_so_far<max_ending_here)
				max_so_far=max_ending_here;

			if(max_ending_here<0)
				max_ending_here=0;
		}
		cout<<max_so_far<<endl;	
	}

	return 0;
}