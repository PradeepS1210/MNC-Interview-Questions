/*
Example 1:
============
Input:
Enter the number of elements: 4
Enter the elements of the array: 1 5 11 5

Output: YES
Explanation: The two parts are {1, 5, 5} and {11}.

Example 2:
============
Input:
Enter the number of elements: 3
Enter the elements of the array: 1 3 5

Output: NO
Explanation: This array can never be partitioned into two such parts.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int equalPartition(int N, int arr[])
    {
        int totalSum = accumulate(arr, arr + N, 0);

        if (totalSum % 2 != 0)
        {
            return 0;
        }

        int target = totalSum / 2;

        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int i = 0; i < N; ++i)
        {
            for (int j = target; j >= arr[i]; --j)
            {
                dp[j] = dp[j] || dp[j - arr[i]];
            }
        }

        return dp[target] ? 1 : 0;
    }
};

int main()
{
    int N;
    cout << "Enter the number of elements: ";
    cin >> N;

    int arr[N];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    Solution sol;
    int result = sol.equalPartition(N, arr);
    if (result == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
