/*
Example:
==========
Input:
Enter the number of elements: 7
Enter the elements of the array:
1 3 20 4 1 0 5

Output:
Index of peak element: 2
Peak element value: 20
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int peakElement(int arr[], int n)
    {
        int left = 0;
        int right = n - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (arr[mid] > arr[mid + 1])
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        return left;
    }
};

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    Solution sol;
    int peakIndex = sol.peakElement(arr, n);

    cout << "Index of peak element: " << peakIndex << endl;
    cout << "Peak element value: " << arr[peakIndex] << endl;

    return 0;
}
