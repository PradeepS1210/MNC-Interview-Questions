/*
Example 1:
=============
Input:
Enter the number of elements in the array: 4
Enter the elements of the array: 1 2 3 2
Enter the value of x: 1
Enter the value of y: 2

Output: Minimum distance between 1 and 2 is: 1
Explanation: x = 1 and y = 2. There are two distances between x and y, which are 1 and 3 out of which the least is 1.

Example 2:
=============
Input:
Enter the number of elements in the array: 7
Enter the elements of the array: 86 39 90 67 84 66 62
Enter the value of x: 42
Enter the value of y: 12

Output: Minimum distance between 42 and 12 is: -1
Explanation: x = 42 and y = 12. We return -1 as x and y don't exist in the array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDist(int a[], int n, int x, int y)
    {
        int lastX = -1, lastY = -1;
        int minDistance = INT_MAX;

        for (int i = 0; i < n; ++i)
        {
            if (a[i] == x)
            {
                lastX = i;
                if (lastY != -1)
                {
                    minDistance = min(minDistance, lastX - lastY);
                }
            }
            if (a[i] == y)
            {
                lastY = i;
                if (lastX != -1)
                {
                    minDistance = min(minDistance, lastY - lastX);
                }
            }
        }

        return (minDistance == INT_MAX) ? -1 : minDistance;
    }
};

int main()
{
    int n, x, y;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int a[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    cout << "Enter the value of x: ";
    cin >> x;
    cout << "Enter the value of y: ";
    cin >> y;

    Solution sol;
    int result = sol.minDist(a, n, x, y);
    cout << "Minimum distance between " << x << " and " << y << " is: " << result << endl;

    return 0;
}
