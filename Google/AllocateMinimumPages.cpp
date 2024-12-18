/*
Examples:
----------
Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Allocation can be done in following ways:
[12] and [34, 67, 90] Maximum Pages = 191
[12, 34] and [67, 90] Maximum Pages = 157
[12, 34, 67] and [90] Maximum Pages = 113.
Therefore, the minimum of these cases is 113, which is selected as the output.

Input: arr[] = [15, 17, 20], k = 5
Output: -1
Explanation: Allocation can not be done.

Input: arr[] = [22, 23, 67], k = 1
Output: 112
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (k > n) return -1;
        
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int result = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(arr, n, k, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
    
private:
    bool isValid(vector<int> &arr, int n, int k, int maxPages) {
        int studentCount = 1, currentSum = 0;
        
        for (int i = 0; i < n; ++i) {
            if (currentSum + arr[i] > maxPages) {
                studentCount++;
                currentSum = arr[i];
                if (studentCount > k) return false;
            } else {
                currentSum += arr[i];
            }
        }
        return true;
    }
};

int main() {
    int n, k;
    cout << "Enter the number of books: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the number of pages in each book: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Enter the number of students: ";
    cin >> k;

    Solution solution;
    int result = solution.findPages(arr, k);

    if (result == -1) {
        cout << "Allocation is not possible." << endl;
    } else {
        cout << "The minimum of the maximum pages allocated is: " << result << endl;
    }

    return 0;
}
