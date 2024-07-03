/*
Example 1:
===========
Input:
Enter the first string: ABCDGH
Enter the second string: AEDFHR

Output: The length of the longest common subsequence is: 3
Explanation: LCS for input strings “ABCDGH” and “AEDFHR” is “ADH” of length 3.

Example 2:
============
Input:
Enter the first string: ABC
Enter the second string: AC

Output: The length of the longest common subsequence is: 2
Explanation: LCS of "ABC" and "AC" is "AC" of length 2.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lcs(int n, int m, string str1, string str2)
    {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }
};

int main()
{
    Solution sol;
    string str1, str2;
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;

    int n = str1.length();
    int m = str2.length();

    int result = sol.lcs(n, m, str1, str2);

    cout << "The length of the longest common subsequence is: " << result << endl;

    return 0;
}
