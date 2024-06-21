/*
Example:
=========
Input:
Enter number of vertices (V) and edges (E): 5 4
Enter the edges (u v) where u -> v:
0 1
0 2
0 3
2 4

Output: BFS Traversal starting from node 0: 0 1 2 3 4

Explanation:
0 is connected to 1 , 2 , 3.
2 is connected to 4.
so starting from 0, it will go to 1 then 2 then 3. After this 2 to 4, thus bfs will be 0 1 2 3 4.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> bfs;
        vector<bool> visited(V, false);
        queue<int> q;

        q.push(0);
        visited[0] = true;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            bfs.push_back(u);

            for (int v : adj[u])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        return bfs;
    }
};

int main()
{
    int V, E;
    cout << "Enter number of vertices (V) and edges (E): ";
    cin >> V >> E;

    vector<int> adj[V];
    cout << "Enter the edges (u v) where u -> v:" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    Solution sol;
    vector<int> bfsTraversal = sol.bfsOfGraph(V, adj);

    cout << "BFS Traversal starting from node 0: ";
    for (int node : bfsTraversal)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
