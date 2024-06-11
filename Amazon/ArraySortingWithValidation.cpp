/*
Example:
=========
Input: N = 5
arr[]= {0 2 1 2 0}
Output: 0 0 1 2 2
Explanation: 0s 1s and 2s are segregated into ascending order.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sort012(int a[], int n)
    {
        int low = 0;
        int mid = 0;
        int high = n - 1;

        while (mid <= high)
        {
            switch (a[mid])
            {
            case 0:
                swap(a[low++], a[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(a[mid], a[high--]);
                break;
            }
        }
    }
};

bool isValidInput(int num)
{
    return (num == 0 || num == 1 || num == 2);
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array (0, 1, or 2 only): ";
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        if (!isValidInput(input))
        {
            cout << "Error: Invalid input. Please enter only 0, 1, or 2." << endl;
            exit(EXIT_FAILURE);
        }
        arr[i] = input;
    }

    Solution obj;
    obj.sort012(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
