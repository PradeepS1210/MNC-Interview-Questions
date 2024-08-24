/*
Example:
==========
Enter the number of items: 3
Enter the values of the items: 1 2 3
Enter the weights of the items: 4 5 1
Enter the knapsack capacity: 4
Maximum value in the knapsack: 3
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int knapSack(int W, vector<int> &wt, vector<int> &val)
    {
        int N = val.size();

        vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

        for (int i = 1; i <= N; ++i)
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

        return dp[N][W];
    }
};

int main()
{
    int N, W;

    cout << "Enter the number of items: ";
    cin >> N;

    vector<int> val(N), wt(N);

    cout << "Enter the values of the items: ";
    for (int i = 0; i < N; ++i)
    {
        cin >> val[i];
    }

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < N; ++i)
    {
        cin >> wt[i];
    }

    cout << "Enter the knapsack capacity: ";
    cin >> W;

    Solution solution;
    int maxValue = solution.knapSack(W, wt, val);

    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}
