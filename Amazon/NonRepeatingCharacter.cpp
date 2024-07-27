/*
Example 1:
============
Input: Enter a string: h
Output: h
Explanation: In the given string, the first character which is non-repeating is h, as it appears first and there is no other 'h' in the string.

Example 2:
============
Input: Enter a string: zxvczbtxyzvy
Output: c
Explanation: In the given string, 'c' is the character which is non-repeating.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char nonrepeatingCharacter(string S)
    {
        unordered_map<char, int> charCount;
        queue<char> charQueue;

        for (char c : S)
        {
            charCount[c]++;
            charQueue.push(c);
        }

        while (!charQueue.empty())
        {
            char c = charQueue.front();
            charQueue.pop();
            if (charCount[c] == 1)
            {
                return c;
            }
        }

        return '$';
    }
};

int main()
{
    Solution sol;
    string s;
    cout << "Enter a string: ";
    cin >> s;
    char result = sol.nonrepeatingCharacter(s);
    if (result == '$')
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << result << endl;
    }
    return 0;
}
