/*
Example 1:
===========
Input:
Enter the number of elements in the array: 5
Enter the elements of the array: 5 1 2 3 4

Output: The array was rotated 1 times.
Explanation: The given array is 5 1 2 3 4. The original sorted array is 1 2 3 4 5. We can see that the array was rotated 1 times to the right.

Example 2:
===========
Input:
Enter the number of elements in the array: 5
Enter the elements of the array: 1 2 3 4 5

Output: The array was rotated 0 times.
Explanation: The given array is not rotated.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKRotation(vector<int> &arr)
    {
        int n = arr.size();
        int low = 0, high = n - 1;

        if (arr[low] < arr[high])
        {
            return 0;
        }

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] > arr[mid + 1])
            {
                return mid + 1;
            }
            if (arr[mid] < arr[mid - 1])
            {
                return mid;
            }

            if (arr[mid] > arr[0])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return 0;
    }
};

int main()
{
    Solution solution;
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int result = solution.findKRotation(arr);
    cout << "The array was rotated " << result << " times." << endl;

    return 0;
}
