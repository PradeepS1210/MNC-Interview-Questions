/*
Examples:
----------
Input: arr[] = [1, 2, 3, 7, 5], target = 12
Output: [2, 4]
Explanation: The sum of elements from 2nd to 4th position is 12.

Input: arr[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], target = 15
Output: [1, 5]
Explanation: The sum of elements from 1st to 5th position is 15.

Input: arr[] = [5, 3, 4], target = 2
Output: [-1]
Explanation: There is no subarray with sum 2.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> subarraySum(vector<int>& arr, int target) {
        int n = arr.size();
        int current_sum = arr[0], start = 0;

        for (int i = 1; i <= n; i++) {
            while (current_sum > target && start < i - 1) {
                current_sum -= arr[start];
                start++;
            }
            if (current_sum == target) {
                return {start + 1, i};
            }
            if (i < n) {
                current_sum += arr[i];
            }
        }
        return {-1};
    }
};

int main() {
    int n, target;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the target sum: ";
    cin >> target;
    
    Solution solution;
    vector<int> result = solution.subarraySum(arr, target);
    
    if (result[0] == -1) {
        cout << "No subarray with the given sum exists" << endl;
    } else {
        cout << "Subarray with the given sum is found from index " << result[0] << " to " << result[1] << endl;
    }
    return 0;
}
