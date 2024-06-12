/*
Example 1:
============
Input: n = 6
arr[] = 7 10 4 3 20 15
k = 3
Output : 7
Explanation :kth smallest element in the given array is 7.

Example 2:
============
Input: n = 5
arr[] = 7 10 4 20 15
k = 4
Output: 15
Explanation: kth smallest element in the given array is 15.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthSmallest(int arr[], int l, int r, int k)
    {
        int pos = partition(arr, l, r);

        if (pos == k - 1)
        {
            return arr[pos];
        }
        else if (pos > k - 1)
        {
            return kthSmallest(arr, l, pos - 1, k);
        }
        else
        {
            return kthSmallest(arr, pos + 1, r, k);
        }
    }

private:
    int partition(int arr[], int l, int r)
    {
        int pivot = arr[r];
        int i = l - 1;

        for (int j = l; j < r; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[r]);
        return i + 1;
    }
};

int main()
{
    Solution sol;
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int l = 0, r = n - 1;
    cout << "Enter the value of k: ";
    cin >> k;

    int result = sol.kthSmallest(arr, l, r, k);

    cout << "The kth smallest element is: " << result << endl;

    delete[] arr;

    return 0;
}
