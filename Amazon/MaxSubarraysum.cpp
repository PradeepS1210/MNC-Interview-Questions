/*Example 1:
==============
Input: arr[] = {1,2,3,-2,5}, n = 5
Output: 9
Explanation: Max subarray sum is 9 of elements (1, 2, 3, -2, 5) which is a contiguous subarray.

Example 2:
==============
Input: arr[] = {5,4,7}, n = 3
Output: 16
Explanation: Max subarray sum is 16 of element (5, 4, 7)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxSubarraySum(int arr[], int n)
    {
        long long maxSum = arr[0];
        long long currentSum = arr[0];

        for (int i = 1; i < n; ++i)
        {
            currentSum = max((long long)arr[i], currentSum + arr[i]);
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};

int main()
{
    Solution sol;

    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << "Maximum subarray sum: " << sol.maxSubarraySum(arr, n) << endl;

    return 0;
}
