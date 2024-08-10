/*
Example 1:
===========
Input:
Enter the number of elements in the array: 5
Enter the elements of the array: 1 101 2 3 100

Output: The maximum sum of the increasing subsequence is: 106
Explanation: The maximum sum of a increasing sequence is obtained from {1, 2, 3, 100}

Example 2:
===========
Input:
Enter the number of elements in the array: 4
Enter the elements of the array: 4 1 2 3

Output: The maximum sum of the increasing subsequence is: 6
Explanation: The maximum sum of a increasing sequence is obtained from {1, 2, 3}.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSumIS(int arr[], int n)
    {
        vector<int> dp(n);

        for (int i = 0; i < n; ++i)
        {
            dp[i] = arr[i];
        }

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i])
                {
                    dp[i] = dp[j] + arr[i];
                }
            }
        }

        int maxSum = 0;
        for (int i = 0; i < n; ++i)
        {
            maxSum = max(maxSum, dp[i]);
        }

        return maxSum;
    }
};

int main()
{
    Solution sol;
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int result = sol.maxSumIS(arr, n);
    cout << "The maximum sum of the increasing subsequence is: " << result << endl;

    return 0;
}
