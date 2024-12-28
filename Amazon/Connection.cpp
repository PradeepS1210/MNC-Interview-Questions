/*
Testcase Input
4 5
1 2 1
1 3 1
1 4 1
3 2 2
4 2 2

Testcase Output
4

Explanation
Removing Edges 4 (between 3 and 2) and 5 (between 4 and 2)  yield a reward of 4. It is the maximum possible reward.
*/

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int x, y, z;
    Edge(int x, int y, int z) : x(x), y(y), z(z) {}
};

int find(vector<int>& fa, int x) {
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa, fa[x]);
}

int main() {
    int n, m;
    cout << "Enter the number of vertices (N) and edges (M): ";
    cin >> n >> m;

    vector<Edge> edges;
    long long ans = 0;

    cout << "Enter the edges (A B C):" << endl;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        edges.emplace_back(x, y, z);
        if (z > 0) {
            ans += z;
        }
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.z < b.z;
    });

    vector<int> fa(n + 1);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }

    for (const auto& edge : edges) {
        int x = find(fa, edge.x);
        int y = find(fa, edge.y);

        if (x == y) {
            continue;
        }

        fa[x] = y;

        if (edge.z > 0) {
            ans -= edge.z;
        }
    }

    cout << "Maximum reward: " << ans << endl;

    return 0;
}
