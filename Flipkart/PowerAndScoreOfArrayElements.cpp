/*
Example 1:
------------
Input
5
4 7 1 8 3

Output
2

Explanation
Index 0 (arr[0] = 4):
Before: INT_MAX (no elements).
After: Second minimum in [7, 1, 8, 3] = 3.
Score: max(4 - INT_MAX, 4 - 3) = 1.

Index 1 (arr[1] = 7):
Before: Second minimum in [4] = INT_MAX.
After: Second minimum in [1, 8, 3] = 3.
Score: max(7 - INT_MAX, 7 - 3) = 4.

Index 2 (arr[2] = 1):
Before: Second minimum in [4, 7] = 7.
After: Second minimum in [8, 3] = 8.
Score: max(1 - 7, 1 - 8) = -6.

Index 3 (arr[3] = 8):
Before: Second minimum in [4, 7, 1] = 4.
After: INT_MAX (no elements).
Score: max(8 - 4, 8 - INT_MAX) = 4.

Index 4 (arr[4] = 3):
Before: Second minimum in [4, 7, 1, 8] = 4.
After: INT_MAX (no elements).
Score: max(3 - 4, 3 - INT_MAX) = -1.

Total Score: 1 + 4 - 6 + 4 - 1 = 2.

Example 2:
-----------
Input
4
3 8 1 6

Output
-5

Explanation
Index 0 (arr[0] = 3):
Before: INT_MAX (no elements).
After: Second minimum in [8, 1, 6] = 6.
Score: max(3 - INT_MAX, 3 - 6) = -3.

Index 1 (arr[1] = 8):
Before: Second minimum in [3] = INT_MAX.
After: Second minimum in [1, 6] = 6.
Score: max(8 - INT_MAX, 8 - 6) = 2.

Index 2 (arr[2] = 1):
Before: Second minimum in [3, 8] = 8.
After: Second minimum in [6] = INT_MAX.
Score: max(1 - 8, 1 - INT_MAX) = -7.

Index 3 (arr[3] = 6):
Before: Second minimum in [3, 8, 1] = 3.
After: INT_MAX (no elements).
Score: max(6 - 3, 6 - INT_MAX) = 3.

Total Score: -3 + 2 - 7 + 3 = -5.
*/

#include <bits/stdc++.h>
using namespace std;

int calculateScore(const vector<int>& arr, int n) {
    vector<int> before(n, INT_MAX);
    vector<int> after(n, INT_MAX);
    set<int> left, right;

    for (int i = 0; i < n; ++i) {
        if (left.size() >= 2) {
            auto it = left.begin();
            ++it;
            before[i] = *it;
        }
        left.insert(arr[i]);
    }
  
    for (int i = n - 1; i >= 0; --i) {
        if (right.size() >= 2) {
            auto it = right.begin();
            ++it;
            after[i] = *it;
        }
        right.insert(arr[i]);
    }
  
    int score = 0;
    for (int i = 0; i < n; ++i) {
        score += max(arr[i] - before[i], arr[i] - after[i]);
    }

    return score;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int score = calculateScore(arr, n);
    cout << score << endl;

    return 0;
}
