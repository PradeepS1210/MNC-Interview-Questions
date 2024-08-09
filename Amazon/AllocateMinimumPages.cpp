/*
Example:
=========
Input:
Enter the number of books: 4
Enter the pages in each book: 12 34 67 90
Enter the number of students: 2

Output: The minimum number of pages that can be assigned to a student is: 113
Explanation: Allocation can be done in following ways:
{12} and {34, 67, 90} Maximum Pages = 191
{12, 34} and {67, 90} Maximum Pages = 157
{12, 34, 67} and {90} Maximum Pages =113.
Therefore, the minimum of these cases is 113, which is selected as the output.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long findPages(int n, int arr[], int m)
    {
        if (m == 0 || n == 0)
            return -1;
        if (n < m)
            return -1;

        long long low = arr[0];
        long long high = 0;
        for (int i = 0; i < n; ++i)
        {
            high += arr[i];
            low = max(low, (long long)arr[i]);
        }

        auto isPossible = [&](long long mid) -> bool
        {
            int studentsRequired = 1;
            long long currentSum = 0;
            for (int i = 0; i < n; ++i)
            {
                if (currentSum + arr[i] > mid)
                {
                    ++studentsRequired;
                    currentSum = arr[i];
                    if (studentsRequired > m)
                        return false;
                }
                else
                {
                    currentSum += arr[i];
                }
            }
            return true;
        };

        while (low < high)
        {
            long long mid = low + (high - low) / 2;
            if (isPossible(mid))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low;
    }
};

int main()
{
    Solution sol;
    int n, m;

    cout << "Enter the number of books: ";
    cin >> n;

    int arr[n];
    cout << "Enter the pages in each book: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << "Enter the number of students: ";
    cin >> m;

    long long result = sol.findPages(n, arr, m);

    if (result == -1)
    {
        cout << "Invalid input or not enough books for students." << endl;
    }
    else
    {
        cout << "The minimum number of pages that can be assigned to a student is: " << result << endl;
    }

    return 0;
}
