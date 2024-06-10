/*Example 1:
=============
Input: n = 5, arr[] = {1,2,3,5}
Output: 4
Explanation : All the numbers from 1 to 5 are present except 4.

Example 2:
===========
Input: n = 2, arr[] = {1}
Output: 2
Explanation : All the numbers from 1 to 2 are present except 2.
*/

#include <bits/stdc++.h>
using namespace std;

int findMissingNumber(int n, vector<int> &arr)
{
    // Sort the array first
    sort(arr.begin(), arr.end());

    // Check for the missing number
    for (int i = 0; i < n - 1; ++i)
    {
        if (arr[i] != i + 1)
        {
            return i + 1;
        }
    }
    // If no missing number found, the missing number is the last number + 1
    return n;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n - 1);
    cout << "Enter " << n - 1 << " numbers of the array (one number is missing): ";
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> arr[i];
    }

    int missingNumber = findMissingNumber(n, arr);
    cout << "The missing number is: " << missingNumber << endl;
    return 0;
}
