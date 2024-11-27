/*
Examples:
--------------------------
Input: arr[] = [1, 0, 1], k = 1
Output: 3
Explanation: Maximum subarray of consecutive 1's is of size 3 which can be obtained after flipping the zero present at the 1st index.

Input: arr[] = [1, 0, 0, 1, 0, 1, 0, 1], k = 2
Output: 5
Explanation: By flipping the zeroes at indices 4 and 6, we get the longest subarray from index 3 to 7 containing all 1’s.

Input: arr[] = [1, 1], k = 2
Output: 2
Explanation: Since the array is already having the max consecutive 1's, hence we dont need to perform any operation. Hence the answer is 2
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOnes(vector<int>& arr, int k) {
        int left = 0, maxLength = 0, zeroCount = 0;

        for (int right = 0; right < arr.size(); ++right) {
            if (arr[right] == 0) {
                zeroCount++;
            }
            
            while (zeroCount > k) {
                if (arr[left] == 0) {
                    zeroCount--;
                }
                left++;
            }
            
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main() {
    int n, k;
    
    cout << "Enter the size of the array: ";
    cin >> n;
    
    vector<int> arr(n);
    
    cout << "Enter the elements of the array (0 or 1): ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    cout << "Enter the value of k (maximum number of 0's to flip): ";
    cin >> k;
    
    Solution sol;
    int result = sol.maxOnes(arr, k);
    
    cout << "The maximum number of consecutive 1's after flipping at most " 
         << k << " 0's is: " << result << endl;
    
    return 0;
}
