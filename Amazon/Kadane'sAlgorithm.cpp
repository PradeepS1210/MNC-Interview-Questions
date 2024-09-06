/*
Example:
==========
Input:
Enter the number of elements in the array: 5
Enter the elements of the array: 1 2 3 -2 5

Output: Maximum sum of contiguous subarray: 9
Explanation: Max subarray sum is 9 of elements (1, 2, 3, -2, 5) which is a contiguous subarray.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxSubarraySum(vector<int> &arr)
    {
        long long current_sum = 0;
        long long max_sum = LLONG_MIN;

        for (int i = 0; i < arr.size(); i++)
        {
            current_sum = max((long long)arr[i], current_sum + arr[i]);
            max_sum = max(max_sum, current_sum);
        }

        return max_sum;
    }
};

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution sol;

    long long max_sum = sol.maxSubarraySum(arr);
    cout << "Maximum sum of contiguous subarray: " << max_sum << endl;

    return 0;
}
