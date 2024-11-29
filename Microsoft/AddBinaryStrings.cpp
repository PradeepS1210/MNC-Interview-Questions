/*
Input: s1 = "1101", s2 = "111"
Output: 10100
Explanation:
 1101
+ 111
10100

Input: s1 = "00100", s2 = "010"
Output: 110
Explanation: 
  100
+  10
  110
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string& s1, string& s2) {
        int i = s1.size() - 1;
        int j = s2.size() - 1;
        int carry = 0;
        string result = "";
        
        while (i >= 0 || j >= 0 || carry > 0) {
            int bit1 = (i >= 0) ? s1[i] - '0' : 0;
            int bit2 = (j >= 0) ? s2[j] - '0' : 0;
            int sum = bit1 + bit2 + carry;
            
            result += (sum % 2) + '0';
            carry = sum / 2;
            
            i--;
            j--;
        }
        
        reverse(result.begin(), result.end());
        
        auto pos = result.find_first_not_of('0');
        return (pos == string::npos) ? "0" : result.substr(pos);
    }
};

int main() {
    string s1, s2;

    cout << "Enter the first binary string: ";
    cin >> s1;
    cout << "Enter the second binary string: ";
    cin >> s2;

    Solution solution;
    string result = solution.addBinary(s1, s2);

    cout << "The sum of the binary strings is: " << result << endl;

    return 0;
}
