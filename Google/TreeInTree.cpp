/*
Example 1:
----------
Input
2
1 2

Output
3
0

Explanation: There is only one single edge in the tree.

Example 2:
----------
Input
4
1 2
2 3
3 4

Output
10
5
0
0

Explanation: The induced subgraph will have two connected components in the following five cases and one in the others.

V={1,2,4}
V={1,3}
V={1,3,4}
V={1,4}
V={2,4}
*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define N 5010

vector<int> adj[N];
long long f[N][2][N];
int n;

void add_edge(int x, int y) {
    adj[x].push_back(y);
    adj[y].push_back(x);
}

int dfs(int x, int fa) {
    int tot = 1;
    f[x][0][0] = 1;
    f[x][1][1] = 1;
    for (auto y : adj[x]) {
        if (y == fa) continue;
        int now = dfs(y, x);
        for (int i = tot; i >= 0; --i) {
            for (int j = now; j > 0; --j) {
                f[x][0][i + j] = (f[x][0][i + j] + (f[x][0][i] * (f[y][0][j] + f[y][1][j]) % MOD) % MOD) % MOD;
            }
        }
        for (int i = tot; i > 0; --i) {
            for (int j = now; j > 0; --j) {
                f[x][1][i + j] = (f[x][1][i + j] + (f[x][1][i] * f[y][0][j]) % MOD) % MOD;
                f[x][1][i + j - 1] = (f[x][1][i + j - 1] + (f[x][1][i] * f[y][1][j]) % MOD) % MOD;
            }
        }
        tot += now;
    }
    return tot;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        add_edge(x, y);
    }
    memset(f, 0, sizeof(f));
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) {
        cout << (f[1][0][i] + f[1][1][i]) % MOD << endl;
    }
    return 0;
}
