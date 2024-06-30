/*
Example 1:
============

Input:
Enter the size of the array: 6
Enter the elements of the array: 5 8 3 7 9 1

Output: Length of the longest increasing subsequence: 3

Explanation: There are more than one LIS in this array. One such Longest increasing subsequence is 5 7 9.

Example 2:
============

Input:
Enter the size of the array: 16
Enter the elements of the array: 0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15

Output: Length of the longest increasing subsequence: 6

Explanation: There are more than one LIS in this array. One such Longest increasing subsequence is 0 2 6 9 13 15.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubsequence(int n, int a[])
    {
        if (n == 0)
            return 0;

        std::vector<int> tail;

        for (int i = 0; i < n; ++i)
        {
            auto it = std::lower_bound(tail.begin(), tail.end(), a[i]);

            if (it == tail.end())
            {
                tail.push_back(a[i]);
            }
            else
            {
                *it = a[i];
            }
        }

        return tail.size();
    }
};

int main()
{
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    int a[n];
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    Solution sol;
    int result = sol.longestSubsequence(n, a);
    std::cout << "Length of the longest increasing subsequence: " << result << std::endl;

    return 0;
}
