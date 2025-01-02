/*
Examples:
----------
Input: arr = [10, 2, -2, -20, 10], k = -10
Output: 3
Explaination: Subarrays: arr[0...3], arr[1...4], arr[3...4] have sum exactly equal to -10.

Input: arr = [9, 4, 20, 3, 10, 5], k = 33
Output: 2
Explaination: Subarrays: arr[0...2], arr[2...4] have sum exactly equal to 33.

Input: arr = [1, 3, 5], k = 0
Output: 0
Explaination: No subarray with 0 sum.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        unordered_map<int, int> prefixSumCount;
        int count = 0, prefixSum = 0;
        prefixSumCount[0] = 1;

        for (int num : arr) {
            prefixSum += num;
            if (prefixSumCount.find(prefixSum - k) != prefixSumCount.end()) {
                count += prefixSumCount[prefixSum - k];
            }
            prefixSumCount[prefixSum]++;
        }

        return count;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    Solution solution;
    int result = solution.countSubarrays(arr, k);
    cout << result << endl;

    return 0;
}
