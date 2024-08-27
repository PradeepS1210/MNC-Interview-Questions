/*
Example:
=========
Input: Enter a Roman numeral: V
Output: The equivalent decimal number is: 5
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int romanToDecimal(string &s)
    {
        unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};

        int n = s.length();
        int result = 0;

        for (int i = 0; i < n; i++)
        {
            if (i < n - 1 && roman[s[i]] < roman[s[i + 1]])
            {
                result -= roman[s[i]];
            }
            else
            {
                result += roman[s[i]];
            }
        }

        return result;
    }
};

int main()
{
    Solution ob;
    string s;

    cout << "Enter a Roman numeral: ";
    cin >> s;

    cout << "The equivalent decimal number is: " << ob.romanToDecimal(s) << endl;

    return 0;
}
