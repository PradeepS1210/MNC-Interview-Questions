/*

Example 1
================================================================
Input:
Enter size of array (n): 5
Enter number of positions to rotate left (d): 2
Enter 5 elements of the array:
1 2 3 4 5

Output:
Rotated array after left rotation by 2 positions:
3 4 5 1 2

Explanation: 1 2 3 4 5  when rotated by 2 elements, it becomes 3 4 5 1 2.

Example 2:
================================================================
Input:
Enter size of array (n): 10
Enter number of positions to rotate left (d): 3
Enter 10 elements of the array:
2 4 6 8 10 12 14 16 18 20

Output:
Rotated array after left rotation by 3 positions:
8 10 12 14 16 18 20 2 4 6

Explanation: 2 4 6 8 10 12 14 16 18 20 when rotated by 3 elements, it becomes 8 10 12 14 16 18 20 2 4 6.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void reverse(int arr[], int start, int end)
    {
        while (start < end)
        {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }

    void rotateArr(int arr[], int d, int n)
    {
        d = d % n;

        reverse(arr, 0, d - 1);

        reverse(arr, d, n - 1);

        reverse(arr, 0, n - 1);
    }
};

int main()
{
    int n, d;
    cout << "Enter size of array (n): ";
    cin >> n;

    cout << "Enter number of positions to rotate left (d): ";
    cin >> d;

    int arr[n];
    cout << "Enter " << n << " elements of the array:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    Solution sol;
    sol.rotateArr(arr, d, n);

    cout << "Rotated array after left rotation by " << d << " positions:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
