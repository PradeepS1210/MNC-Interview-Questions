/*
Examples:
-----------
Input: arr[] = [2, 6, 1, 9, 4, 5, 3]
Output: 6
Explanation: The consecutive numbers here are 1, 2, 3, 4, 5, 6. These 6 numbers form the longest consecutive subsquence.

Input: arr[] = [1, 9, 3, 10, 4, 20, 2]
Output: 4
Explanation: 1, 2, 3, 4 is the longest consecutive subsequence.

Input: arr[] = [15, 13, 12, 14, 11, 10, 9]
Output: 7
Explanation: The longest consecutive subsequence is 9, 10, 11, 12, 13, 14, 15, which has a length of 7.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int> nums(arr.begin(), arr.end());
        int longestStreak = 0;

        for (int num : nums) {
            if (nums.find(num - 1) == nums.end()) {
                int currentNum = num;
                int currentStreak = 1;

                while (nums.find(currentNum + 1) != nums.end()) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};

int main() {
    Solution sol;

    cout << "Enter the number of elements: ";
    int n;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int result = sol.longestConsecutive(arr);

    cout << "The length of the longest consecutive subsequence is: " << result << endl;

    return 0;
}
