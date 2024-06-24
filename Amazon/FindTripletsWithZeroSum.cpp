/*

Example:
===========
Input:
Enter size of array: 5
Enter 5 elements of the array:
0 -1 2 -3 1

Output: Array contains a triplet with sum zero.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool findTriplets(int arr[], int n)
    {
        sort(arr, arr + n);

        for (int i = 0; i < n - 2; ++i)
        {
            if (i > 0 && arr[i] == arr[i - 1])
            {
                continue;
            }

            int left = i + 1;
            int right = n - 1;
            int target = -arr[i];

            while (left < right)
            {
                int sum = arr[left] + arr[right];
                if (sum == target)
                {
                    return true;
                }
                else if (sum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }

        return false;
    }
};

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements of the array:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    Solution sol;
    bool found = sol.findTriplets(arr, n);

    if (found)
    {
        cout << "Array contains a triplet with sum zero." << endl;
    }
    else
    {
        cout << "Array does not contain a triplet with sum zero." << endl;
    }

    return 0;
}
