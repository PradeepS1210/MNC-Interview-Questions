/*
Example 1:
============
Input: Enter the input string: "aabc"
Output: "a#bb"
Explanation:
For every ith character we will consider the string from index 0 till index i first non repeating character is as follow-
"a" - first non-repeating character is 'a'
"aa" - no non-repeating character so '#'
"aab" - first non-repeating character is 'b'
"aabc" - there are two non repeating characters 'b' and 'c',
first non-repeating character is 'b' because 'b' comes before 'c' in the stream.

Example 2:
============
Input: Enter the input string: "zz"
Output: "z#"
Explanation: For every character first non repeating character is as follow-
"z" - first non-repeating character is 'z'
"zz" - no non-repeating character so '#'
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        unordered_map<char, int> charCount;
        deque<char> uniqueChars;
        string result;

        for (char c : A)
        {
            charCount[c]++;

            if (charCount[c] == 1)
            {
                uniqueChars.push_back(c);
            }

            while (!uniqueChars.empty() && charCount[uniqueChars.front()] > 1)
            {
                uniqueChars.pop_front();
            }

            if (uniqueChars.empty())
            {
                result += '#';
            }
            else
            {
                result += uniqueChars.front();
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    string input;
    cout << "Enter the input string: ";
    cin >> input;

    string output = sol.FirstNonRepeating(input);
    cout << "Output: " << output << endl;

    return 0;
}
