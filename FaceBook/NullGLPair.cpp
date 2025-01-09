/*
Example 1
-----------
Input
2
4 7

Output
0

Explanation
The only possible pair is GL(1,2) = LCM(4,7) - GCD(4,7) = 28-1 = 27, which is not equal to 0.

Example 2
-----------
Input
5
1 3 3 3 7

Output
3

Explanation
There are only 3 pairs that have GL(i,j) = 0.
(2,3), (3,4), and (2,4),
(2,3) = LCM(3,3) - GCD(3,3) = 3-3 = 0.
(3,4) = LCM(3,3) - GCD(3,3) = 3-3 = 0.
(2,4) = LCM(3,3) - GCD(3,3) = 3-3 = 0.
*/

#include <bits/stdc++.h>
using namespace std;

int countPairs(int n, vector<int>& num) {
    unordered_map<int, int> mp;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        mp[num[i]]++;
    }

    for (auto it : mp) {
        int count = it.second;
        ans += (count * (count - 1)) / 2; 
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    
    cout << countPairs(n, num) << endl;

    return 0;
}
