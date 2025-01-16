/*
Examples:
----------
Input: arr[] = [1, 0, 1, 1, 1, 0, 0]
Output: 6
Explanation: arr[1...6] is the longest subarray with three 0s and three 1s.

Input: arr[] = [0, 0, 1, 1, 0]
Output: 4
Explnation: arr[0...3] or arr[1...4] is the longest subarray with two 0s and two 1s.

Input: arr[] = [0]
Output: 0
Explnation: There is no subarray with an equal number of 0s and 1s.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxLen(vector<int> &arr) {
        unordered_map<int, int> hash_map;
        int max_len = 0, sum = 0;

        for (int i = 0; i < arr.size(); ++i) {
            sum += (arr[i] == 0) ? -1 : 1;

            if (sum == 0)
                max_len = i + 1;

            if (hash_map.find(sum) != hash_map.end()) {
                max_len = max(max_len, i - hash_map[sum]);
            } else {
                hash_map[sum] = i;
            }
        }

        return max_len;
    }
};

int main() {
    Solution sol;
    int n;
    
    cout << "Enter the size of the array: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements of the array (0s and 1s): ";
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int result = sol.maxLen(arr);
    cout << "The length of the longest subarray with equal number of 0s and 1s is: " << result << endl;

    return 0;
}
