/*
Example 1:
============
Input:
Enter the number of elements in the array: 6
Enter the elements of the array: 1 4 45 6 10 8
Enter the target sum: 16

Output: Output: Yes
Explanation: arr[3] + arr[4] = 6 + 10 = 16

Example 2:
============
Input:
Enter the number of elements in the array: 5
Enter the elements of the array: 1 2 4 3 6
Enter the target sum: 10

Output: Output: Yes
Explanation: arr[2] + arr[4] = 4 + 6 = 10
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasArrayTwoCandidates(int arr[], int n, int x)
    {
        unordered_set<int> seen;

        for (int i = 0; i < n; ++i)
        {
            int complement = x - arr[i];

            if (seen.find(complement) != seen.end())
            {
                return true;
            }

            seen.insert(arr[i]);
        }

        return false;
    }
};

int main()
{
    Solution sol;

    int n, x;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << "Enter the target sum: ";
    cin >> x;

    bool result = sol.hasArrayTwoCandidates(arr, n, x);
    if (result)
    {
        cout << "Output: Yes" << endl;
    }
    else
    {
        cout << "Output: No" << endl;
    }

    return 0;
}
