/*
Example 1:
============
Enter the number of elements in the array: 6
Enter the elements of the array: 5 2 3 10 6 8
Enter the sum to find subsets for: 10

Output: The number of subsets with sum 10 is: 3

Example 2:
============
Enter the number of elements in the array: 5
Enter the elements of the array: 1 2 3 4 5
Enter the sum to find subsets for: 5

Output: The number of subsets with sum 5 is: 3
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int perfectSum(int arr[], int n, int sum)
    {
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (arr[i - 1] <= j)
                {
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i - 1]]) % MOD;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][sum];
    }
};

int main()
{
    int n, sum;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the sum to find subsets for: ";
    cin >> sum;

    Solution sol;
    int result = sol.perfectSum(arr, n, sum);

    cout << "The number of subsets with sum " << sum << " is: " << result << endl;

    return 0;
}
