/*
Example:
==========
Input:
Enter the number of vertices: 5
Enter the number of edges: 4
Enter the edges (u v) one by one:
0 2
0 3
0 1
2 4

Output: DFS Traversal starting from vertex 0: 0 2 4 3 1

Explanation:
  0
 /|\
2 3 1
|
4

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int node, vector<int> adj[], vector<bool> &visited, vector<int> &dfsResult)
    {
        visited[node] = true;
        dfsResult.push_back(node);
        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                dfs(neighbor, adj, visited, dfsResult);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> dfsResult;
        vector<bool> visited(V, false);
        dfs(0, adj, visited, dfsResult);
        return dfsResult;
    }
};

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<int> adj[V];
    cout << "Enter the edges (u v) one by one:" << endl;
    for (int i = 0; i < E; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Solution obj;
    vector<int> result = obj.dfsOfGraph(V, adj);

    cout << "DFS Traversal starting from vertex 0: ";
    for (int node : result)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
