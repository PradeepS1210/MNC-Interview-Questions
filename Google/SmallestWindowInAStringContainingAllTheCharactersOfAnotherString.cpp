/*
Example
==========
Input:
Enter string s: timetopractice
Enter string p: toc

Output: The smallest window is: toprac
Explanation: "toprac" is the smallest substring in which "toc" can be found.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string smallestWindow(string s, string p)
    {
        int n = s.length();
        int m = p.length();

        if (n < m)
            return "-1";

        int charCountP[256] = {0};
        for (char c : p)
        {
            charCountP[c]++;
        }

        for (char c : p)
        {
            if (charCountP[c] > 0 && s.find(c) == std::string::npos)
            {
                return "-1";
            }
        }

        int start = 0, minLength = INT_MAX, startIndex = -1;
        int charCountS[256] = {0};
        int requiredUniqueChars = 0;
        int matchedUniqueChars = 0;

        for (int i = 0; i < 256; i++)
        {
            if (charCountP[i] > 0)
                requiredUniqueChars++;
        }

        for (int end = 0; end < n; end++)
        {
            char currentChar = s[end];
            charCountS[currentChar]++;

            if (charCountP[currentChar] > 0 && charCountS[currentChar] == charCountP[currentChar])
            {
                matchedUniqueChars++;
            }

            while (matchedUniqueChars == requiredUniqueChars)
            {
                if (end - start + 1 < minLength)
                {
                    minLength = end - start + 1;
                    startIndex = start;
                }

                char leftChar = s[start];
                charCountS[leftChar]--;

                if (charCountP[leftChar] > 0 && charCountS[leftChar] < charCountP[leftChar])
                {
                    matchedUniqueChars--;
                }

                start++;
            }
        }

        if (startIndex == -1)
            return "-1";

        return s.substr(startIndex, minLength);
    }
};

int main()
{
    Solution sol;
    string s, p;

    cout << "Enter string s: ";
    getline(std::cin, s);
    cout << "Enter string p: ";
    getline(std::cin, p);

    string result = sol.smallestWindow(s, p);

    cout << "The smallest window is: " << result << std::endl;

    return 0;
}