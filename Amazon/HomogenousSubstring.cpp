/*
Example 1:
------------
Input
xy

Output
2

Explanation
The homogenous substrings are "x" and "y".

Example 2:
------------
Input
abbcccaa

Output
13

Explanation
The homogenous substrings are listed as below:

"a" appears 3 times.
"aa" appears 1 time.
"b" appears 2 times.
"bb" appears 1 time.
"c" appears 3 times.
"cc" appears 2 times.
"ccc" appears 1 time.

Total count: 3 + 1 + 2 + 1 + 3 + 2 + 1 = 13.
*/

#include <iostream>
#include <string>

using namespace std;

const int MOD = 1e9 + 7;

int countHomogeneousSubstrings(const string& str) {
    long long count = 0;
    int n = str.size();
    
    for (int i = 0; i < n; ++i) {
        int length = 1;
        while (i + 1 < n && str[i] == str[i + 1]) {
            ++length;
            ++i;
        }
        count = (count + (long long)length * (length + 1) / 2) % MOD;
    }
    
    return count;
}

int main() {
    string str;
    cin >> str;
    
    int result = countHomogeneousSubstrings(str);
    cout << result << endl;
    
    return 0;
}
