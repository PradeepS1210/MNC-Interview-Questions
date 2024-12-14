/*
Examples :
-----------
Input: arr[] = [5, 6, 7, 8, 9, 10, 1, 2, 3], key = 3
Output: 8
Explanation: 3 is found at index 8.

Input: arr[] = [3, 5, 1, 2], key = 6
Output: -1
Explanation: There is no element that has value 6.

Input: arr[] = [33, 42, 72, 99], key = 42
Output: 1
Explanation: 42 is found at index 1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& arr, int target) {
        int start = 0, end = arr.size() - 1, mid;
        
        while (start <= end) {
            mid = start + (end - start) / 2;

            if (arr[mid] == target)
                return mid;
            // Left Side Sorted    
            else if (arr[mid] >= arr[0]) {
                if (arr[start] <= target && arr[mid] > target)
                    end = mid - 1;
                else
                    start = mid + 1;
            }
            // Right Side Sorted
            else {
                if (arr[mid] < target && arr[end] >= target)
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;

    int n, target;
    cout << "Enter the number of elements in the rotated sorted array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the rotated sorted array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Enter the target value to search: ";
    cin >> target;

    int result = solution.search(arr, target);

    if (result != -1) {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found in the array." << endl;
    }

    return 0;
}
