/*
Example 1:
-----------
Input
cocodeinecodecodecode

Output
2

Explanation
The vowel reversed a string of "cocodeinecodecodecode" will be “cecodeonecodecidecodo.”
The number of occurrences of “code” in “cecodeonecodecidecodo” is 2.

Example 2:
-----------
Input
tecodezcodewhcodembcodi

Output
4

Explanation

1. Original String: "tecodezcodewhcodembcodi"
2. Reverse Vowels: "ticodemcodewhcodembcodoe"
3. Count "code" occurrences: There are four occurrences of the substring "code" in the reversed string: "ticodemcodewhcodembcodoe"

First occurrence: "ticodemcode" (starting from index 2)
Second occurrence: "codemcode" (starting from index 8)
Third occurrence: "mcode" (starting from index 17)
Fourth occurrence: "codoe" (starting from index 22)

Therefore, the output of the program is 4, as it correctly counts the occurrences of the substring "code" in the reversed string.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countReversedVowel(string s) {
        string vowels = "aeiou";
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (vowels.find(s[left]) == string::npos) {
                left++;
            } else if (vowels.find(s[right]) == string::npos) {
                right--;
            } else {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        string target = "code";
        int count = 0;
        for (size_t i = 0; i <= s.size() - target.size(); i++) {
            if (s.substr(i, target.size()) == target) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.countReversedVowel(s) << endl;
    return 0;
}
