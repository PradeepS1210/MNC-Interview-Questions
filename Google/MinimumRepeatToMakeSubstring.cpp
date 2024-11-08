/*
Examples:
============
Input: s1 = "ww", s2 = "www"
Output: 2
Explanation: Repeating s1 two times (wwww), s2 is a substring of it.

Input: s1 = "abcd", s2 = "cdabcdab" 
Output: 3 
Explanation: Repeating s1 three times (abcdabcdabcd), s2 is a substring of it. s2 is not a substring of s2 when it is repeated less than 3 times.

Input: s1 = "ab", s2 = "cab"
Output: -1
Explanation: No matter how many times we repeat s1, we can't get a string such that s2 is a substring of it.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        string repeated = s1;
        int count = 1;

        while (repeated.length() < s2.length()) {
            repeated += s1;
            count++;
        }

        if (repeated.find(s2) != string::npos) {
            return count;
        }

        repeated += s1;
        count++;

        if (repeated.find(s2) != string::npos) {
            return count;
        }

        return -1;
    }
};

int main() {
    string s1, s2;
    cout << "Enter the first string (s1): ";
    cin >> s1;
    cout << "Enter the second string (s2): ";
    cin >> s2;

    Solution solution;
    int result = solution.minRepeats(s1, s2);

    if (result == -1) {
        cout << "It is not possible to make s2 a substring of any number of repetitions of s1." << endl;
    } else {
        cout << "Minimum number of repeats needed: " << result << endl;
    }

    return 0;
}
