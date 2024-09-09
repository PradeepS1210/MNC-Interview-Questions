/*
Example:
==========
Input:
Enter the size of the array: 5
Enter the elements of the array (0s, 1s, 2s): 0 2 1 2 0

Output: Sorted array: 0 0 1 2 2
Explanation: 0s 1s and 2s are segregated into ascending order.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sort012(vector<int> &arr)
    {
        int low = 0, mid = 0;
        int high = arr.size() - 1;

        while (mid <= high)
        {
            if (arr[mid] == 0)
            {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if (arr[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array (0s, 1s, 2s): ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution sol;
    sol.sort012(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
