/*
Examples:
----------
Input: s = "geeksforgeeks"
Output: 7
Explanation: "eksforg" is the longest substring with all distinct characters.

Input: s = "aaa"
Output: 1
Explanation: "a" is the longest substring with all distinct characters.

Input: s = "abcdefabcbb"
Output: 6
Explanation: The longest substring with all distinct characters is "abcdef", which has a length of 6.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestUniqueSubstr(string &s) {
        unordered_map<char, int> lastIndex;
        int maxLength = 0, start = 0;

        for (int end = 0; end < s.length(); ++end) {
            if (lastIndex.find(s[end]) != lastIndex.end()) {
                start = max(start, lastIndex[s[end]] + 1);
            }
            lastIndex[s[end]] = end;
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << "The length of the longest substring is: " 
         << sol.longestUniqueSubstr(s) << endl;
    return 0;
}
