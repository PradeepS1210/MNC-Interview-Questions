/*
Example:
==========
Input: Enter the value of n: 4

Output:
Total number of solutions: 2
2 4 1 3
3 1 4 2

Explaination: These are the 2 possible solutions.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> nQueen(int n)
    {
        vector<vector<int>> result;
        vector<int> board(n, 0);
        vector<bool> columns(n, false);
        vector<bool> diagonals1(2 * n - 1, false);
        vector<bool> diagonals2(2 * n - 1, false);
        solve(0, n, board, result, columns, diagonals1, diagonals2);
        return result;
    }

private:
    void solve(int row, int n, vector<int> &board, vector<vector<int>> &result,
               vector<bool> &columns, vector<bool> &diagonals1, vector<bool> &diagonals2)
    {
        if (row == n)
        {
            result.push_back(board);
            return;
        }
        for (int col = 0; col < n; ++col)
        {
            if (columns[col] || diagonals1[row + col] || diagonals2[row - col + n - 1])
            {
                continue;
            }
            board[row] = col + 1;
            columns[col] = diagonals1[row + col] = diagonals2[row - col + n - 1] = true;
            solve(row + 1, n, board, result, columns, diagonals1, diagonals2);
            // Backtrack
            columns[col] = diagonals1[row + col] = diagonals2[row - col + n - 1] = false;
        }
    }
};

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    Solution sol;
    vector<vector<int>> solutions = sol.nQueen(n);

    cout << "Total number of solutions: " << solutions.size() << endl;
    for (const auto &solution : solutions)
    {
        for (int val : solution)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
