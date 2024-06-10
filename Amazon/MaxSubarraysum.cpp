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
