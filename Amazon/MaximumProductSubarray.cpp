/*

Example 1:
===========
Input:
N = 5
Arr[] = {6, -3, -10, 0, 2}
Output: 180
Explanation: Subarray with maximum product is [6, -3, -10] which gives product as 180.

Example 2:
===========
Input:
N = 6
Arr[] = {2, 3, 4, 5, -1, 0}
Output: 120
Explanation: Subarray with maximum product is [2, 3, 4, 5] which gives product as 120.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxProduct(vector<int> &arr, int n)
    {
        long long maxProduct = arr[0];
        long long currMax = arr[0];
        long long currMin = arr[0];

        for (int i = 1; i < n; i++)
        {
            if (arr[i] < 0)
            {
                swap(currMax, currMin);
            }

            currMax = max((long long)arr[i], currMax * arr[i]);
            currMin = min((long long)arr[i], currMin * arr[i]);

            maxProduct = max(maxProduct, currMax);
        }

        return maxProduct;
    }
};

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution sol;
    long long result = sol.maxProduct(arr, n);

    cout << "The maximum product subarray is: " << result << endl;

    return 0;
}
