/*
Example:
============
Input:
Enter the first string: ABCDGH
Enter the second string: ACDGHR

Output: Length of the longest common substring: 4
Explanation: The longest common substring is "CDGH" which has length 4.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCommonSubstr(string s1, string s2)
    {
        int m = s1.length();
        int n = s2.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int maxLength = 0;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    maxLength = max(maxLength, dp[i][j]);
                }
            }
        }

        return maxLength;
    }
};

int main()
{
    Solution sol;
    string s1, s2;

    cout << "Enter the first string: ";
    getline(cin, s1);

    cout << "Enter the second string: ";
    getline(cin, s2);

    int result = sol.longestCommonSubstr(s1, s2);

    cout << "Length of the longest common substring: " << result << endl;

    return 0;
}
