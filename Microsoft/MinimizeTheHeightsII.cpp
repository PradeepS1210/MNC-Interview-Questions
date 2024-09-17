/*
Example:
==========
Input:
Enter number of towers: 4
Enter the value of k: 2
Enter the heights of the towers: 1 5 8 10

Output: The minimum possible difference is: 5
Explanation: The array can be modified as {1+k, 5-k, 8-k, 10-k} = {3, 3, 6, 8}.The difference between the largest and the smallest is 8-3 = 5.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMinDiff(vector<int> &arr, int k)
    {
        int n = arr.size();
        if (n == 1)
        {
            return 0;
        }

        sort(arr.begin(), arr.end());

        int diff = arr[n - 1] - arr[0];

        int smallest, largest;

        for (int i = 0; i < n - 1; i++)
        {
            smallest = min(arr[0] + k, arr[i + 1] - k);
            largest = max(arr[n - 1] - k, arr[i] + k);

            if (smallest >= 0)
            {
                diff = min(diff, largest - smallest);
            }
        }

        return diff;
    }
};

int main()
{
    int n, k;

    cout << "Enter number of towers: ";
    cin >> n;

    cout << "Enter the value of k: ";
    cin >> k;

    vector<int> arr(n);

    cout << "Enter the heights of the towers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution solution;
    int result = solution.getMinDiff(arr, k);

    cout << "The minimum possible difference is: " << result << endl;

    return 0;
}
