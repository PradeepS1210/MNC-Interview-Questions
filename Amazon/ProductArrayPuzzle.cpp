/*
Example 1:
============
Input:
Enter the number of elements in the array: 5
Enter the elements of the array: 10 3 5 6 2

Output: Product array is: 180 600 360 300 900
Explanation:
For i=0, P[i] = 3*5*6*2 = 180.
For i=1, P[i] = 10*5*6*2 = 600.
For i=2, P[i] = 10*3*6*2 = 360.
For i=3, P[i] = 10*3*5*2 = 300.
For i=4, P[i] = 10*3*5*6 = 900.

Example 2:
============
Input:
Enter the number of elements in the array: 2
Enter the elements of the array: 12 0

Output: Product array is: 0 12
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long int> productExceptSelf(vector<long long int> &nums)
    {
        int n = nums.size();
        vector<long long int> prefix(n, 1);
        vector<long long int> suffix(n, 1);
        vector<long long int> result(n);

        for (int i = 1; i < n; ++i)
        {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        for (int i = n - 2; i >= 0; --i)
        {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; ++i)
        {
            result[i] = prefix[i] * suffix[i];
        }

        return result;
    }
};

int main()
{
    Solution sol;
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<long long int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    vector<long long int> result = sol.productExceptSelf(nums);

    cout << "Product array is: ";
    for (long long int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
