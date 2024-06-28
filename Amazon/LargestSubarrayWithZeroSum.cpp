/*
Example:
==========
Input:
Enter the number of elements in the array: 8
Enter the elements of the array: 15 -2 2 -8 1 7 10 23

Output:
Length of the largest subarray with sum 0 is: 5

Explanation: The largest subarray with sum 0 is -2 2 -8 1 7.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxLen(vector<int> &arr, int n)
    {
        unordered_map<int, int> sumIndex;
        int maxLength = 0;
        int sum = 0;

        for (int i = 0; i < n; ++i)
        {
            sum += arr[i];

            if (sum == 0)
            {
                maxLength = i + 1;
            }
            else
            {
                if (sumIndex.find(sum) != sumIndex.end())
                {
                    maxLength = max(maxLength, i - sumIndex[sum]);
                }
                else
                {
                    sumIndex[sum] = i;
                }
            }
        }

        return maxLength;
    }
};

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    Solution sol;
    int maxLength = sol.maxLen(arr, n);

    cout << "Length of the largest subarray with sum 0 is: " << maxLength << endl;

    return 0;
}
