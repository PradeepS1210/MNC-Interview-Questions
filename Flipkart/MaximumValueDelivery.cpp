/*
Example 1:
-----------
Input
3 2
2 61
6 30
1 93
7 2

Output
154

Explanation
A delivery company has 3 packages with weights and values of (2, 61), (6, 30), and (1, 93), and 2 delivery trucks with capacities of 7 and 2.

The company wants to maximize the total value of delivered packages.
We can assign the first package to the first truck with capacity 7, and the third package to the second truck with capacity 2.

The total value of the delivered packages is 61 + 93 = 154.

Example 2:
-----------
Input
4 2
1 10
2 5 
3 12
4 7
3 5

Testcase Output
22

Explanation
A delivery company has 4 packages with weights and values of (1, 10), (2, 5), (3, 12) and (4, 7), and 2 delivery trucks with capacities of 3 and 5.


The company wants to maximize the total value of delivered packages.
We can assign the first package to the first truck with capacity 3 and the third package to the second truck with capacity 5.

The total value of the delivered packages is 10 + 12 = 22.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<pair<int, int>> v;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    
    vector<int> C(K);
    for (int i = 0; i < K; ++i) {
        cin >> C[i];
    }
    
    sort(C.begin(), C.end());
    sort(v.begin(), v.end());
    
    priority_queue<int> pq;
    int ans = 0;
    int idx1 = 0, idx2 = 0;
    
    while (idx1 < v.size() && idx2 < C.size()) {
        while (idx1 < v.size() && v[idx1].first <= C[idx2]) {
            pq.push(v[idx1].second);
            ++idx1;
        }
        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        ++idx2;
    }
    
    cout << ans << endl;
    
    return 0;
}
