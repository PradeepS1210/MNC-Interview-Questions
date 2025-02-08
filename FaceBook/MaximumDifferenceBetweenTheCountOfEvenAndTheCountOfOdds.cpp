/*
Example 1
-----------
Input
3
1 1 1

Output
-1

Explanation
No even number is present.

Example 2
-----------
Input
5
1 2 3 4 5

Output
1

Explanation
There are 3 subarrays which give a maximum difference of 1.

(No. Of even - No. Of odd)
(2) -> 1-0=1
(2,3,4)-> 2-1=1
(4)->1-0=1
*/

#include <bits/stdc++.h>
using namespace std;

int maxDifferenceEvenOdd(vector<int>& V) {
    int N = V.size();
    bool hasEven = false;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        if (V[i] % 2 == 0) {
            arr[i] = 1;
            hasEven = true;
        } else {
            arr[i] = -1;
        }
    }

    if (!hasEven) return -1;

    int maxSum = INT_MIN, currentSum = 0;
    for (int i = 0; i < N; i++) {
        currentSum += arr[i];
        maxSum = max(maxSum, currentSum);
        if (currentSum < 0) currentSum = 0;
    }

    return maxSum;
}

int main() {
    int N;
    cin >> N;
    vector<int> V(N);
    
    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }
    
    cout << maxDifferenceEvenOdd(V) << endl;
    
    return 0;
}
