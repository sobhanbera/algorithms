//Link->https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/* Function to do DFS of graph

g : adjacency list of graph
N : number of vertices

return a list containing the DFS traversal of the given graph
*/
void dfsTraverseRecur(bool visited[],vector<int> adj[],int v,vector<int> &vect) {

	visited[v]=true;
	vect.push_back(v);
	for(vector<int>::const_iterator it=adj[v].begin(); it!=adj[v].end(); it++) {
		if(visited[*it]!=true) {
			dfsTraverseRecur(visited,adj,*it,vect);
		}
	}

}
vector <int> dfs(vector<int> g[], int N)
{
    
    // Your code here
    
    bool visited[N];
    vector<int> vect;
	for(int i=0; i<N; i++)
		visited[i]=false;
	dfsTraverseRecur(visited,g,0,vect);
	return vect;

}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {

        int N, E;
        cin>>N>>E;
        
        vector<int> g[N];
        bool vis[N];
        
        memset(vis, false, sizeof(vis));
        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector <int> res = dfs(g, N);
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout<<endl;

    }
}  // } Driver Code Ends
