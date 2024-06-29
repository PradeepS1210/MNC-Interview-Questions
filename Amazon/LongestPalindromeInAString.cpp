/*
Example 1:
============
Input: Enter the string: aaaabbaa
Output: Longest palindromic substring: aabbaa
Explanation: The longest Palindromic substring is "aabbaa".

Example 2:
============
Input: Enter the string: abc
Output: Longest palindromic substring: a
Explanation: "a", "b" and "c" are the longest palindromes with same length. The result is the one with the least starting index.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestPalin(string S)
    {
        int n = S.size();
        if (n == 0)
            return "";

        int start = 0, maxLength = 1;

        for (int i = 0; i < n; ++i)
        {
            int low = i, high = i;
            while (low >= 0 && high < n && S[low] == S[high])
            {
                if (high - low + 1 > maxLength)
                {
                    start = low;
                    maxLength = high - low + 1;
                }
                --low;
                ++high;
            }

            low = i, high = i + 1;
            while (low >= 0 && high < n && S[low] == S[high])
            {
                if (high - low + 1 > maxLength)
                {
                    start = low;
                    maxLength = high - low + 1;
                }
                --low;
                ++high;
            }
        }

        return S.substr(start, maxLength);
    }
};

int main()
{
    Solution sol;
    string str;

    cout << "Enter the string: ";
    cin >> str;

    string result = sol.longestPalin(str);
    cout << "Longest palindromic substring: " << result << endl;

    return 0;
}
