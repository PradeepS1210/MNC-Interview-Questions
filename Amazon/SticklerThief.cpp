/*
Example 1:
============
Input:
Enter the number of houses: 5
Enter the amounts in the houses: 6 5 5 7 4

Output: Maximum amount the thief can loot: 15
Explanation: Maximum amount he can get by looting 1st, 3rd and 5th house. Which is 6+5+4=15.

Example 2:
============
Input:
Enter the number of houses: 3
Enter the amounts in the houses: 1 5 3

Output: Maximum amount the thief can loot: 5
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int FindMaxSum(int arr[], int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return arr[0];

        int prev1 = arr[0];
        int prev2 = max(arr[0], arr[1]);

        for (int i = 2; i < n; ++i)
        {
            int curr = max(arr[i] + prev1, prev2);
            prev1 = prev2;
            prev2 = curr;
        }

        return prev2;
    }
};

int main()
{
    Solution sol;
    int n;
    cout << "Enter the number of houses: ";
    cin >> n;
    int arr[n];
    cout << "Enter the amounts in the houses: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int maxLoot = sol.FindMaxSum(arr, n);
    cout << "Maximum amount the thief can loot: " << maxLoot << endl;

    return 0;
}
