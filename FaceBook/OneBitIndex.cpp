/*
Sample Testcase 0
-------------------
Testcase Input
1
9
Testcase Output
0
Explanation
The array is [9]
Sum till the first index is 9, which in binary has a two-bit set.
Therefore, we have zero good indexes in the array.

Sample Testcase 1
-------------------
Testcase Input
3
1 2 5
Testcase Output
2
Explanation
The array is [1, 2, 5]
Sum till the first index is 1; in binary, it has only one bit set.
The sum till the second index is 3; in binary, it has a two-bit set.
The sum till the third index is 8; in binary, it has only a 1-bit set.
Therefore, a number of good indices in the array are 2.
*/

#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int x) {
    return (x > 0) && ((x & (x - 1)) == 0);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int goodIndices = 0;
    long long prefixSum = 0;

    for (int i = 0; i < n; ++i) {
        prefixSum += arr[i];
        if (isPowerOfTwo(prefixSum)) {
            ++goodIndices;
        }
    }

    cout << goodIndices << endl;
    return 0;
}
