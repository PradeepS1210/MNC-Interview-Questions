/*
Example 1:
-----------
Input
4
2 6 4 8

Output
4

Explanation
We can group all the elements of the array in a single group, i.e., [2, 4, 6, 8].

Example 2:
-----------
Input
5  
6 2 4 6 8

Output
2

Explanation
There are multiple ways to group the array elements.
For example:  
[2, 4, 6, 8]  and [6]. In this case, the minimum size of the subset is 1.
But since we want to maximize the minimum subset size, we can group the array elements as [2, 4, 6] [6, 8].
Here the minimum subset size is 2, which is the maximum possible size among all other possibilities.
*/

#include <bits/stdc++.h>
using namespace std;

int subMax(vector<int>& arr, int n) {
    sort(arr.begin(), arr.end());
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;

    for (int i = 0; i < n; ++i) {
        int cur = arr[i];
        int prev = cur - 2;
        int sz = 0;

        if (mp.count(prev) && !mp[prev].empty()) {
            sz = mp[prev].top();
            mp[prev].pop();
        }

        sz += 1;

        if (!mp.count(cur)) {
            mp[cur] = priority_queue<int, vector<int>, greater<int>>();
        }
        mp[cur].push(sz);
    }

    int ans = n;
    for (auto& ent : mp) {
        if (!ent.second.empty()) {
            ans = min(ans, ent.second.top());
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int res = subMax(arr, n);
    cout << res << endl;
    return 0;
}
