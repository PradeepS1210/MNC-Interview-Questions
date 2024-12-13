/*
Examples:
----------
Input: arr[] = [5, 6, 1, 2, 3, 4]
Output: 1
Explanation: 1 is the minimum element in the array.

Input: arr[] = [3, 2, 2, 2]
Output: 2
Explanation: Here 2 is the minimum element.

Input: arr[] = [4, 4, 4]
Output: 4
Explanation: Here 4 is the only minimum element.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int findMin(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] > arr[right]) {
                left = mid + 1;
            } else if (arr[mid] < arr[right]) {
                right = mid;
            } else {
                right--;
            }
        }
        return arr[left];
    }
};

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    Solution solution;
    int result = solution.findMin(arr);

    cout << "The minimum element in the array is: " << result << endl;
    return 0;
}
