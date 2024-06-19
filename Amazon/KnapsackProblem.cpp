/*
Example:
==========
Input:
Enter the capacity of the knapsack: 50
Enter the number of items: 3
Enter the weights of the items:
10
20
30
Enter the values of the items:
60
100
120

Output: Maximum value that can be put in knapsack = 220

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int knapSack(int W, int wt[], int val[], int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

        for (int i = 1; i <= n; ++i)
        {
            for (int w = 1; w <= W; ++w)
            {
                if (wt[i - 1] <= w)
                {
                    dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
                }
                else
                {
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }

        return dp[n][W];
    }
};

int main()
{
    Solution sol;

    int W;
    int n;

    cout << "Enter the capacity of the knapsack: ";
    cin >> W;
    cout << "Enter the number of items: ";
    cin >> n;

    int wt[n];
    int val[n];

    cout << "Enter the weights of the items:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> wt[i];
    }

    cout << "Enter the values of the items:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> val[i];
    }

    int maxValue = sol.knapSack(W, wt, val, n);

    cout << "Maximum value that can be put in knapsack = " << maxValue << endl;

    return 0;
}
