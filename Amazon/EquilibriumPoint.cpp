/*
Example 1:
============
Input: n = 5
A[] = {1,3,5,2,2}
Output: 3
Explanation: equilibrium point is at position 3 as sum of elements before it (1+3) = sum of elements after it (2+2).

Example 2:
============
Input: n = 1
A[] = {1}
Output: 1
Explanation: Since there's only element hence its only the equilibrium point.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int equilibriumPoint(long long a[], int n)
    {
        if (n == 1)
            return 1;

        long long total_sum = 0;
        for (int i = 0; i < n; i++)
        {
            total_sum += a[i];
        }

        long long left_sum = 0;

        for (int i = 0; i < n; i++)
        {
            long long right_sum = total_sum - left_sum - a[i];

            if (left_sum == right_sum)
            {
                return i + 1;
            }

            left_sum += a[i];
        }

        return -1;
    }
};

int main()
{
    Solution sol;
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    long long a[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int result = sol.equilibriumPoint(a, n);
    cout << "Equilibrium Point: " << result << endl;

    return 0;
}
