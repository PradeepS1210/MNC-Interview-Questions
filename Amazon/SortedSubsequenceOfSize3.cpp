/*
Example:
=========
Input:
Enter the number of elements in the array: 6
Enter the elements of the array: 1 2 1 1 3 2

Output: Triplet found: 1, 2, 3

Explanation: A subsequence 1 2 3 exist.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> find3Numbers(vector<int> &arr)
    {
        int n = arr.size();
        if (n < 3)
            return {};

        int smaller[n];
        int larger[n];

        smaller[0] = -1;
        int min_index = 0;

        for (int i = 1; i < n; i++)
        {
            if (arr[i] <= arr[min_index])
            {
                min_index = i;
                smaller[i] = -1;
            }
            else
            {
                smaller[i] = min_index;
            }
        }

        larger[n - 1] = -1;
        int max_index = n - 1;

        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] >= arr[max_index])
            {
                max_index = i;
                larger[i] = -1;
            }
            else
            {
                larger[i] = max_index;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (smaller[i] != -1 && larger[i] != -1)
            {
                return {arr[smaller[i]], arr[i], arr[larger[i]]};
            }
        }

        return {};
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
    vector<int> result = sol.find3Numbers(arr);

    if (result.empty())
    {
        cout << "No such triplet found.\n";
    }
    else
    {
        cout << "Triplet found: " << result[0] << ", " << result[1] << ", " << result[2] << endl;
    }

    return 0;
}
