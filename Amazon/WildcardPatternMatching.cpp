/*
Example 1:
==========
Enter the wildcard pattern: ba*a?
Enter the string: baaabab
Pattern matches the string.

Example 2:
==========
Enter the wildcard pattern: a*ab
Enter the string: baaabab
Pattern does not match the string.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int wildCard(string pattern, string str)
    {
        int n = pattern.size();
        int m = str.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;

        for (int i = 1; i <= n; i++)
        {
            if (pattern[i - 1] == '*')
            {
                dp[i][0] = dp[i - 1][0];
            }
            else
            {
                break;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (pattern[i - 1] == '*')
                {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else if (pattern[i - 1] == '?' || pattern[i - 1] == str[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m] ? 1 : 0;
    }
};

int main()
{
    string pattern, str;
    cout << "Enter the wildcard pattern: ";
    cin >> pattern;
    cout << "Enter the string: ";
    cin >> str;

    Solution sol;
    int result = sol.wildCard(pattern, str);

    if (result == 1)
    {
        cout << "Pattern matches the string." << endl;
    }
    else
    {
        cout << "Pattern does not match the string." << endl;
    }

    return 0;
}
