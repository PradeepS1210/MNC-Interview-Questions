/*
Example 1:
============
Input:
Enter the number of elements in the array: 5
Enter the elements of the array: 15 2 45 4 7

Output: Elements that match their 1-based index: 2, 4
Explanation:
Here, arr[2] = 2 exists here.
and arr[4] = 4 exists here.

Example 2:
============
Input:
Enter the number of elements in the array: 1
Enter the elements of the array: 1

Output: Elements that match their 1-based index: 1
Explanation: Here arr[1] = 1 exists.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> valueEqualToIndex(vector<int> &arr)
    {
        vector<int> result;
        int n = arr.size();

        for (int i = 0; i < n; ++i)
        {
            if (arr[i] == i + 1)
            {
                result.push_back(arr[i]);
            }
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

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    vector<int> result = sol.valueEqualToIndex(arr);

    if (result.empty())
    {
        cout << "No elements match the condition." << endl;
    }
    else
    {
        cout << "Elements that match their 1-based index: ";
        for (int i = 0; i < result.size(); ++i)
        {
            cout << result[i];
            if (i < result.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << endl;
    }

    return 0;
}
