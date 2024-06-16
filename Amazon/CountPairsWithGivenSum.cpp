/*
Example:
============
Input:N = 4,
arr[] = {1, 1, 1, 1}
K = 2
Output: 6
Explanation: Each 1 will produce sum 2 with any 1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getPairsCount(int arr[], int n, int k)
    {
        unordered_map<int, int> freq;
        int countPairs = 0;

        for (int i = 0; i < n; ++i)
        {
            int complement = k - arr[i];

            if (freq.find(complement) != freq.end())
            {
                countPairs += freq[complement];
            }

            freq[arr[i]]++;
        }

        return countPairs;
    }
};

int main()
{
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << "Enter the value of K: ";
    cin >> k;

    Solution sol;
    int result = sol.getPairsCount(arr, n, k);

    cout << "Number of pairs with sum equal to " << k << ": " << result << endl;

    return 0;
}
