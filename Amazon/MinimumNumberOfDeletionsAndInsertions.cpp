#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(string str1, string str2)
    {
        int m = str1.length();
        int n = str2.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int lcsLength = dp[m][n];

        return (m - lcsLength) + (n - lcsLength);
    }
};

int main()
{
    string str1, str2;
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;

    Solution solution;
    int result = solution.minOperations(str1, str2);

    cout << "Minimum number of operations to convert \"" << str1 << "\" into \"" << str2 << "\": " << result << endl;

    return 0;
}
