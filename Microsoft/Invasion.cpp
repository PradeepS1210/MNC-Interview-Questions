/*
Example 1:
-----------
Input
2
0 1

Output
1

Explanation
Installing an antenna on Vertex 0.

Example 2:
-----------
Input
5
0 1
0 2
0 3
3 4

Output
2

Explanation
Install cameras on houses 1 and 3.

The following vectors are distinct


(d(1,0),d(3,0))= (1,1)

(d(1,1),d(3,1))= (0,2)

(d(1,2),d(3,2))= (2,2)

(d(1,3),d(3,3))= (2,0)

(d(1,4),d(3,4))= (3,1)
*/

#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5;
int n, ans = 0;
bool vis[N + 5], flag = true;
vector<int> g[N + 5];

void dfs(int u, int fa) {
    if (g[u].size() > 2) {
        if (!vis[u]) {
            ans--;
            vis[u] = true;
            flag = false;
        }
        return;
    }
    for (int i = 0; i < g[u].size(); i++) {
        if (g[u][i] != fa) {
            dfs(g[u][i], u);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        if (g[i].size() == 1) {
            ans++;
            dfs(i, -1);
        }
    }

    cout << ans - flag << endl;

    return 0;
}
