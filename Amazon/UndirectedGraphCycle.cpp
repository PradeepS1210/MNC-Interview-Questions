/*
Example 1:
============

Input:
Enter the number of vertices (V) and edges (E): 4 4
Enter the edges (format: u v):
0 1
1 2
2 3
3 0

Output: The graph contains a cycle.

Representation of graph with 4 vertices and 4 edges:
  0-----1
  |     |
  |     |
  3-----2


Example 2:
============

Input:
Enter the number of vertices (V) and edges (E): 4 3
Enter the edges (format: u v):
0 1
1 2
2 3

Output: The graph does not contain a cycle.

Representation of graph with 4 vertices and 3 edges:
   0-----1
         |
         |
         2-----3


*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int v, vector<int> adj[], vector<bool> &visited, int parent)
    {
        visited[v] = true;

        for (int u : adj[v])
        {
            if (!visited[u])
            {
                if (dfs(u, adj, visited, v))
                {
                    return true;
                }
            }
            else if (u != parent)
            {
                return true;
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, adj, visited, -1))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    int V, E;
    cout << "Enter the number of vertices (V) and edges (E): ";
    cin >> V >> E;

    vector<int> adj[V];

    cout << "Enter the edges (format: u v):" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Solution sol;
    if (sol.isCycle(V, adj))
    {
        cout << "The graph contains a cycle." << endl;
    }
    else
    {
        cout << "The graph does not contain a cycle." << endl;
    }

    return 0;
}
