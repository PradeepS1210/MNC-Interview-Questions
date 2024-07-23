/*
Example 1:
============
Input:
Enter number of elements in array: 9
Enter elements of the array: 5 6 7 8 9 10 1 2 3
Enter key to search: 10

Output: Key 10 is found at index 5

Example 2:
============
Input:
Enter number of elements in array: 4
Enter elements of the array: 3 5 1 2
Enter key to search: 6

Output: Key 6 is not found in the array
*/

#include <bits/stdc++.h>
using namespace std;

int findKeyInRotatedArray(const vector<int> &arr, int key)
{
    int left = 0, right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }

        if (arr[left] <= arr[mid])
        {
            if (arr[left] <= key && key < arr[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else
        {
            if (arr[mid] < key && key <= arr[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    int n, key;
    cout << "Enter number of elements in array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << "Enter key to search: ";
    cin >> key;

    int index = findKeyInRotatedArray(arr, key);
    if (index != -1)
    {
        cout << "Key " << key << " is found at index " << index << endl;
    }
    else
    {
        cout << "Key " << key << " is not found in the array" << endl;
    }

    return 0;
}
