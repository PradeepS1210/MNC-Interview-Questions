/*
Example 1:
===========
Input:
Enter the number of vertices: 4
Enter the number of edges: 4
Enter the edges (u v) where u -> v:
0 1
1 2
2 3
3 1

Output: The graph contains a cycle.

Example 2:
===========
Input:
Enter the number of vertices: 4
Enter the number of edges: 3
Enter the edges (u v) where u -> v:
0 1
1 2
2 3

Output: The graph does not contain any cycle.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int v, vector<int> adj[], vector<bool> &visited, vector<bool> &recStack)
    {
        visited[v] = true;
        recStack[v] = true;

        for (int neighbour : adj[v])
        {
            if (!visited[neighbour] && dfs(neighbour, adj, visited, recStack))
                return true;
            else if (recStack[neighbour])
                return true;
        }

        recStack[v] = false;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        for (int i = 0; i < V; i++)
            if (!visited[i] && dfs(i, adj, visited, recStack))
                return true;

        return false;
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
    cout << "Enter the edges (u v) where u -> v:" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    Solution sol;
    bool hasCycle = sol.isCyclic(V, adj);

    if (hasCycle)
    {
        cout << "The graph contains a cycle." << endl;
    }
    else
    {
        cout << "The graph does not contain any cycle." << endl;
    }

    return 0;
}
