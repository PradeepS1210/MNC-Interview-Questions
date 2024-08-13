/*
Example 1:
============
Input:
Enter the number of coins: 3
Enter the coin denominations: 25 10 5
Enter the target sum: 30

Output: Minimum number of coins needed: 2

Example 2:
============
Input:
Enter the number of coins: 4
Enter the coin denominations: 9 6 5 1
Enter the target sum: 19

Output: Minimum number of coins needed: 3
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCoins(vector<int> &coins, int sum)
    {
        if (sum == 0)
            return 0;

        vector<int> dp(sum + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= sum; ++i)
        {
            for (int coin : coins)
            {
                if (i >= coin && dp[i - coin] != INT_MAX)
                {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[sum] == INT_MAX ? -1 : dp[sum];
    }
};

int main()
{
    Solution sol;
    int n, sum;

    cout << "Enter the number of coins: ";
    cin >> n;

    vector<int> coins(n);

    cout << "Enter the coin denominations: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> coins[i];
    }

    cout << "Enter the target sum: ";
    cin >> sum;

    int result = sol.minCoins(coins, sum);

    if (result == -1)
    {
        cout << "Not possible to make the given sum." << endl;
    }
    else
    {
        cout << "Minimum number of coins needed: " << result << endl;
    }

    return 0;
}
