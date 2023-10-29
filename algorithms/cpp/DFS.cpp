#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int ver = 7;
    vector<vector<int>> adj(ver);

    // Adding edges
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(5);
    adj[2].push_back(6);

    cout << "Depth-First Traversal (starting from vertex 0): ";

    int str = 0;
    vector<bool> vis(ver, false);
    stack<int> stack;

    vis[str] = true;
    stack.push(str);

    while (!stack.empty())
    {
        int vertex = stack.top();
        cout << vertex << " ";
        stack.pop();

        for (int m : adj[vertex])
        {
            if (!vis[m])
            {
                vis[m] = true;
                stack.push(m);
            }
        }
    }

    return 0;
}
