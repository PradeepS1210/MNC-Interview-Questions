/*
Example 1:
============
Input: arr[] = {0,3,1,2}, n = 4
Output: -1
Explanation: There is no repeating element in the array. Therefore output is -1.

Example 2:
============
Input: arr[] = {2,3,1,2,3}, n = 5
Output: 2 3
Explanation: 2 and 3 occur more than once in the given array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> duplicates(long long arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            arr[arr[i] % n] += n;
        }

        vector<int> result;

        bool foundDuplicates = false;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] / n > 1)
            {
                result.push_back(i);
                foundDuplicates = true;
            }
        }

        if (!foundDuplicates)
        {
            result.push_back(-1);
        }

        return result;
    }
};

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    long long arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution sol;
    vector<int> result = sol.duplicates(arr, n);

    if (result.size() == 1 && result[0] == -1)
    {
        cout << "There is no repeating element in the array. Therefore output is -1." << endl;
    }
    else
    {
        cout << "The duplicates in the array are: ";
        for (int i : result)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
