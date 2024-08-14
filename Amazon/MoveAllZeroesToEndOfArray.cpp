/*
Example 1:
============
Input:
Enter the number of elements: 5
Enter the elements of the array: 3 5 0 0 4

Output: Array after pushing zeros to the end: 3 5 4 0 0

Example 2:
============
Input:
Enter the number of elements: 4
Enter the elements of the array: 0 0 0 4

Output: Array after pushing zeros to the end: 4 0 0 0
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void pushZerosToEnd(int arr[], int n)
    {
        int count = 0;

        for (int i = 0; i < n; ++i)
        {
            if (arr[i] != 0)
            {
                arr[count++] = arr[i];
            }
        }

        while (count < n)
        {
            arr[count++] = 0;
        }
    }
};

int main()
{
    Solution sol;
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int *arr = new int[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    sol.pushZerosToEnd(arr, n);

    cout << "Array after pushing zeros to the end: ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}
