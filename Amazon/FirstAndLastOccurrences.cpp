/*
Example 1:
============
Input:
Enter the number of elements in the array: 9
Enter the elements of the array: 1 3 5 5 5 5 67 123 125
Enter the element to find: 5

Output: First and last occurrences of 5: 2 5

Example 2:
============
Input:
Enter the number of elements in the array: 9
Enter the elements of the array: 1 3 5 5 5 5 7 123 125
Enter the element to find: 7

Output: First and last occurrences of 7: 6 6
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> find(int arr[], int n, int x)
    {
        vector<int> result(2, -1);
        int left = 0, right = n - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] == x)
            {
                result[0] = mid;
                right = mid - 1;
            }
            else if (arr[mid] < x)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        left = 0, right = n - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] == x)
            {
                result[1] = mid;
                left = mid + 1;
            }
            else if (arr[mid] < x)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return result;
    }
};

int main()
{
    int n, x;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << "Enter the element to find: ";
    cin >> x;

    Solution sol;
    vector<int> result = sol.find(arr, n, x);

    cout << "First and last occurrences of " << x << ": ";
    cout << result[0] << " " << result[1] << endl;

    delete[] arr;
    return 0;
}
