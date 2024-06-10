/*
Examples 1:
=============
Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}, n = 11
Output: 3
Explanation:First jump from 1st element to 2nd element with value 3. From here we jump to 5th element with value 9, and from here we will jump to the last.

Examples 2:
============
Input: arr = {1, 4, 3, 2, 6, 7}, n = 6
Output: 2
Explanation: First we jump from the 1st to 2nd element and then jump to the last element.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minJumps(int arr[], int n)
    {
        if (n <= 1)
            return 0;

        if (arr[0] == 0)
            return -1;

        int maxReach = arr[0];
        int steps = arr[0];
        int jumps = 1;

        for (int i = 1; i < n; i++)
        {
            if (i == n - 1)
                return jumps;

            maxReach = max(maxReach, i + arr[i]);

            steps--;

            if (steps == 0)
            {
                jumps++;
                if (i >= maxReach)
                    return -1;
                steps = maxReach - i;
            }
        }

        return -1;
    }
};

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    Solution sol;
    int result = sol.minJumps(arr, n);

    if (result != -1)
        cout << "Minimum number of jumps needed: " << result << endl;
    else
        cout << "End is unreachable." << endl;

    return 0;
}
