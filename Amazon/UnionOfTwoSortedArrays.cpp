/*
Example:
=========
Input:
Enter the size of the first array: 5
Enter elements of the first array: 1 2 3 4 5
Enter the size of the second array: 5
Enter elements of the second array: 1 2 3 6 7

Output: Union of the two arrays:

Explanation: Distinct elements including both the arrays are: 1 2 3 4 5 6 7.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> unionArray;
        int i = 0, j = 0;

        while (i < n && j < m)
        {
            while (i > 0 && i < n && arr1[i] == arr1[i - 1])
                i++;
            while (j > 0 && j < m && arr2[j] == arr2[j - 1])
                j++;

            if (i == n || j == m)
                break;

            if (arr1[i] < arr2[j])
            {
                unionArray.push_back(arr1[i]);
                i++;
            }
            else if (arr1[i] > arr2[j])
            {
                unionArray.push_back(arr2[j]);
                j++;
            }
            else
            {
                unionArray.push_back(arr1[i]);
                i++;
                j++;
            }
        }

        while (i < n)
        {
            if (i == 0 || arr1[i] != arr1[i - 1])
            {
                unionArray.push_back(arr1[i]);
            }
            i++;
        }

        while (j < m)
        {
            if (j == 0 || arr2[j] != arr2[j - 1])
            {
                unionArray.push_back(arr2[j]);
            }
            j++;
        }

        return unionArray;
    }
};

int main()
{
    int n, m;
    cout << "Enter the size of the first array: ";
    cin >> n;
    int arr1[n];
    cout << "Enter elements of the first array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter the size of the second array: ";
    cin >> m;
    int arr2[m];
    cout << "Enter elements of the second array: ";
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    Solution sol;
    vector<int> result = sol.findUnion(arr1, arr2, n, m);
    cout << "Union of the two arrays: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
