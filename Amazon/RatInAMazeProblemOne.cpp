/*
Example 1:
============
Input:
Enter the size of the matrix (N): 4
Enter the matrix elements (0 or 1):
1 0 0 0
1 1 0 1
1 1 0 0
0 1 1 1

Output: DDRDRR DRDDRR

Example 2:
============
Input:
Enter the size of the matrix (N): 2
Enter the matrix elements (0 or 1):
1 0
1 0

Output: -1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void backtrack(vector<vector<int>> &m, int n, int x, int y, vector<string> &result, string path, vector<vector<int>> &visited)
    {
        if (x == n - 1 && y == n - 1)
        {
            result.push_back(path);
            return;
        }

        visited[x][y] = 1;

        if (x + 1 < n && m[x + 1][y] == 1 && !visited[x + 1][y])
        {
            backtrack(m, n, x + 1, y, result, path + 'D', visited);
        }
        if (y - 1 >= 0 && m[x][y - 1] == 1 && !visited[x][y - 1])
        {
            backtrack(m, n, x, y - 1, result, path + 'L', visited);
        }
        if (y + 1 < n && m[x][y + 1] == 1 && !visited[x][y + 1])
        {
            backtrack(m, n, x, y + 1, result, path + 'R', visited);
        }
        if (x - 1 >= 0 && m[x - 1][y] == 1 && !visited[x - 1][y])
        {
            backtrack(m, n, x - 1, y, result, path + 'U', visited);
        }

        visited[x][y] = 0;
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> result;

        if (m[0][0] == 0)
        {
            return result;
        }

        vector<vector<int>> visited(n, vector<int>(n, 0));

        backtrack(m, n, 0, 0, result, "", visited);

        sort(result.begin(), result.end());

        return result;
    }
};

int main()
{
    int n;
    cout << "Enter the size of the matrix (N): ";
    cin >> n;

    vector<vector<int>> m(n, vector<int>(n));
    cout << "Enter the matrix elements (0 or 1): " << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> m[i][j];
        }
    }

    Solution obj;
    vector<string> result = obj.findPath(m, n);

    if (result.empty())
    {
        cout << "-1" << endl;
    }
    else
    {
        for (const string &path : result)
        {
            cout << path << " ";
        }
        cout << endl;
    }

    return 0;
}
