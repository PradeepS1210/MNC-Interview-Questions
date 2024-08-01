/*
Example 1:
============
Input:
Enter the length of the rod (n): 4
Enter the length of the first cut (x): 2
Enter the length of the second cut (y): 1
Enter the length of the third cut (z): 1

Output: Maximum number of cuts: 4
Explanation:Total length is 4, and the cut lengths are 2, 1 and 1.  We can make maximum 4 segments each of length 1.

Example 2:
============
Input:
Enter the length of the rod (n): 5
Enter the length of the first cut (x): 5
Enter the length of the second cut (y): 3
Enter the length of the third cut (z): 2

Output: Maximum number of cuts: 2
Explanation: Here total length is 5, and the cut lengths are 5, 3 and 2. We can make two segments of lengths 3 and 2.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n + 1, -1);
        dp[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            if (i >= x && dp[i - x] != -1)
                dp[i] = max(dp[i], dp[i - x] + 1);
            if (i >= y && dp[i - y] != -1)
                dp[i] = max(dp[i], dp[i - y] + 1);
            if (i >= z && dp[i - z] != -1)
                dp[i] = max(dp[i], dp[i - z] + 1);
        }

        return dp[n] < 0 ? 0 : dp[n];
    }
};

int main()
{
    Solution sol;
    int n, x, y, z;

    cout << "Enter the length of the rod (n): ";
    cin >> n;
    cout << "Enter the length of the first cut (x): ";
    cin >> x;
    cout << "Enter the length of the second cut (y): ";
    cin >> y;
    cout << "Enter the length of the third cut (z): ";
    cin >> z;

    int result = sol.maximizeTheCuts(n, x, y, z);

    cout << "Maximum number of cuts: " << result << endl;

    return 0;
}
