/*
Example:
=========
Input:
Enter the size of the array: 6
Enter the elements of the array: 7 10 4 3 20 15
Enter the value of k: 3

Output: The 3-th smallest element is: 7
Explanation: 3rd smallest element in the given array is 7.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int partition(vector<int> &arr, int low, int high)
    {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

    int quickSelect(vector<int> &arr, int low, int high, int k)
    {
        if (low <= high)
        {
            int pivotIndex = partition(arr, low, high);

            if (pivotIndex == k - 1)
                return arr[pivotIndex];

            if (pivotIndex > k - 1)
                return quickSelect(arr, low, pivotIndex - 1, k);

            return quickSelect(arr, pivotIndex + 1, high, k);
        }
        return -1;
    }

    int kthSmallest(vector<int> &arr, int k)
    {
        int n = arr.size();
        return quickSelect(arr, 0, n - 1, k);
    }
};

int main()
{
    int n, k;

    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    Solution solution;
    int result = solution.kthSmallest(arr, k);

    cout << "The " << k << "-th smallest element is: " << result << endl;

    return 0;
}
