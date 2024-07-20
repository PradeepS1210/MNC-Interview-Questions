/*
Example 1:
============
Input:
Enter the number of elements: 6
Enter the elements: 3 34 4 12 5 2
Enter the sum: 9

Output: 1
Explanation: Here there exists a subset with sum = 9, 4+3+2 = 9.

Example 2:
============
Input:
Enter the number of elements: 4
Enter the elements: 1 2 3 4
Enter the sum: 20

Output: 0
Explanation: There is no subset with sum 20.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        int N = arr.size();
        vector<vector<bool>> dp(N + 1, vector<bool>(sum + 1, false));

        for (int i = 0; i <= N; i++)
        {
            dp[i][0] = true;
        }

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (arr[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[N][sum];
    }
};

int main()
{
    int N, sum;
    cout << "Enter the number of elements: ";
    cin >> N;

    vector<int> arr(N);
    cout << "Enter the elements: ";
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the sum: ";
    cin >> sum;

    Solution sol;
    bool result = sol.isSubsetSum(arr, sum);
    cout << (result ? 1 : 0) << endl;

    return 0;
}
