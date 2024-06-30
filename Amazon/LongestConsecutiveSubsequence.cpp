/*
Example 1:
============
Input:
Enter the size of the array: 7
Enter the elements of the array: 2 6 1 9 4 5 3

Output: Length of the longest subsequence of consecutive integers: 6

Explanation:
The consecutive numbers here are 1, 2, 3, 4, 5, 6. These 6 numbers form the longest consecutive subsquence.

Example 2:
============

Input:
Enter the size of the array: 7
Enter the elements of the array: 1 9 3 10 4 20 2

Output: Length of the longest subsequence of consecutive integers: 4

Explanation:
1, 2, 3, 4 is the longest consecutive subsequence.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLongestConseqSubseq(int arr[], int N)
    {
        if (N == 0)
            return 0;

        unordered_set<int> s(arr, arr + N);

        int longest_streak = 0;

        for (int i = 0; i < N; i++)
        {
            if (s.find(arr[i] - 1) == s.end())
            {
                int current_num = arr[i];
                int current_streak = 1;

                while (s.find(current_num + 1) != s.end())
                {
                    current_num += 1;
                    current_streak += 1;
                }

                longest_streak = max(longest_streak, current_streak);
            }
        }

        return longest_streak;
    }
};

int main()
{
    int N;
    cout << "Enter the size of the array: ";
    cin >> N;

    int arr[N];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    Solution sol;
    int result = sol.findLongestConseqSubseq(arr, N);
    cout << "Length of the longest subsequence of consecutive integers: " << result << endl;

    return 0;
}
