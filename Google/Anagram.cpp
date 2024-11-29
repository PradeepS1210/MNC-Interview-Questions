/*
Examples :
------------
Input: s1 = "geeks", s2 = "kseeg"
Output: true
Explanation: Both the string have same characters with same frequency. So, they are anagrams.

Input: s1 = "allergy", s2 = "allergic"
Output: false
Explanation: Characters in both the strings are not same, so they are not anagrams.

Input: s1 = "g", s2 = "g"
Output: true
Explanation: Character in both the strings are same, so they are anagrams.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areAnagrams(string& s1, string& s2) {
        if (s1.length() != s2.length()) {
            return false;
        }

        unordered_map<char, int> freqMap;

        for (char c : s1) {
            freqMap[c]++;
        }

        for (char c : s2) {
            freqMap[c]--;
            if (freqMap[c] < 0) {
                return false;
            }
        }

        for (auto& pair : freqMap) {
            if (pair.second != 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    string s1, s2;

    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;

    Solution sol;
    if (sol.areAnagrams(s1, s2)) {
        cout << "The strings are anagrams of each other." << endl;
    } else {
        cout << "The strings are not anagrams of each other." << endl;
    }

    return 0;
}
