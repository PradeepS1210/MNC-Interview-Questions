/*
Example 1:
============
Input:
Enter the size of the array: 6
Enter the elements of the array: 1 4 45 6 10 8
Enter the sum to find: 13

Output: 1

Explanation: The triplet {1, 4, 8} in the array sums up to 13.

Example 2:
============
Input:
Enter the size of the array: 6
Enter the elements of the array: 40 20 10 3 6 7
Enter the sum to find: 24

Output: 0

Explanation: There is no triplet with sum 24.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool find3Numbers(int arr[], int n, int x)
    {
        sort(arr, arr + n);

        for (int i = 0; i < n - 2; i++)
        {
            int left = i + 1;
            int right = n - 1;

            while (left < right)
            {
                int sum = arr[i] + arr[left] + arr[right];

                if (sum == x)
                {
                    return true;
                }
                else if (sum < x)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }

        return false;
    }
};

int main()
{
    int n, x;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the sum to find: ";
    cin >> x;

    Solution solution;
    if (solution.find3Numbers(arr, n, x))
    {
        cout << "1\n";
    }
    else
    {
        cout << "0\n";
    }

    return 0;
}
