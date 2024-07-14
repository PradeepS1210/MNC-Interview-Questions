/*
Example:
===========
Input:
Enter the number of people at the party: 3
Enter the matrix (row by row):
0 1 0
0 0 0
0 1 0

Output: The celebrity at the party is person 1.

Explanation: 0th and 2nd person both know 1. Therefore, 1 is the celebrity.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            s.push(i);
        }

        while (s.size() > 1)
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();

            if (M[a][b] == 1)
            {
                s.push(b);
            }
            else
            {
                s.push(a);
            }
        }

        int candidate = s.top();
        s.pop();

        for (int i = 0; i < n; i++)
        {
            if (i != candidate && M[candidate][i] == 1)
            {
                return -1;
            }
            if (i != candidate && M[i][candidate] == 0)
            {
                return -1;
            }
        }

        return candidate;
    }
};

int main()
{
    int n;
    cout << "Enter the number of people at the party: ";
    cin >> n;

    vector<vector<int>> M(n, vector<int>(n));
    cout << "Enter the matrix (row by row):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> M[i][j];
        }
    }

    Solution sol;
    int result = sol.celebrity(M, n);

    if (result == -1)
    {
        cout << "There is no celebrity at the party.\n";
    }
    else
    {
        cout << "The celebrity at the party is person " << result << ".\n";
    }

    return 0;
}
