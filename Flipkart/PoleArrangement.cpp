/*
Example 1:
-----------
Input
4 3
2 3 1 4

Output
0

Explanation
The poles have heights 2, 3, 1, and 4. After reducing the tallest pole (height 4) by x = 3, its new height is 1.
The modified heights are 2, 3, 1, and 1. It is impossible to find three poles where the middle one is the tallest, the first is the shortest, and the last is in between the other two. Therefore, the output is 0.

Example 2:
-----------
Input
3 0
1 3 2

Output
1

Explanation
The three poles have heights 1, 3, and 2. The middle pole (height 3) is the tallest, the first pole (height 1) is the shortest, and the last pole (height 2) is taller than the first but shorter than the middle.
Since no reduction was applied (x = 0), the tent can be made, so the output is 1.
*/

#include <bits/stdc++.h>
using namespace std;

void changeLongest(vector<int>& arr, int x) {
    int maxx = *max_element(arr.begin(), arr.end());
    for (int& height : arr) {
        if (height == maxx) {
            height = max(0, height - x);
        }
    }
}

bool poleArrangement(const vector<int>& arr) {
    int n = arr.size();
    vector<int> pre_min(n);
    pre_min[0] = arr[0];

    for (int i = 1; i < n; ++i) {
        pre_min[i] = min(pre_min[i - 1], arr[i]);
    }

    stack<int> st;

    for (int j = n - 1; j >= 0; --j) {
        if (arr[j] > pre_min[j]) {
            while (!st.empty() && st.top() <= pre_min[j]) {
                st.pop();
            }
            if (!st.empty() && st.top() < arr[j]) {
                return true;
            }
            st.push(arr[j]);
        }
    }

    return false;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    changeLongest(arr, x);
    cout << poleArrangement(arr) << endl;
    
    return 0;
}
