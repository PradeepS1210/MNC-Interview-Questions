/*
Examples:
===========
Enter the number of test cases: 2

Enter the size of the array: 3
Enter the elements of the array: 1 3 3
Repeating number: 3, Missing number: 2

Enter the size of the array: 5
Enter the elements of the array: 1 2 3 4 5
No repeating or missing element
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findTwoElement(vector<int> arr, int n)
    {
        long long sum_n = (long long)n * (n + 1) / 2;
        long long sum_n_sq = (long long)n * (n + 1) * (2 * n + 1) / 6;

        long long sum_arr = 0, sum_arr_sq = 0;
        unordered_set<int> seen;
        int repeating = -1;
        for (int i = 0; i < n; ++i)
        {
            sum_arr += arr[i];
            sum_arr_sq += (long long)arr[i] * arr[i];
            if (seen.find(arr[i]) != seen.end())
            {
                repeating = arr[i];
            }
            seen.insert(arr[i]);
        }

        if (repeating == -1)
        {
            return {0, 0}; // No repeating or missing element
        }

        long long diff = sum_n - sum_arr;               // A - B
        long long sum = (sum_n_sq - sum_arr_sq) / diff; // A + B

        int missing = (diff + sum) / 2;

        return {repeating, missing};
    }
};

int main()
{
    int T;
    cout << "Enter the number of test cases: ";
    cin >> T;
    while (T--)
    {
        int n;
        cout << "Enter the size of the array: ";
        cin >> n;
        vector<int> arr(n);
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }

        Solution solution;
        vector<int> result = solution.findTwoElement(arr, n);

        if (result[0] == 0 && result[1] == 0)
        {
            cout << "No repeating or missing element" << endl;
        }
        else
        {
            cout << "Repeating number: " << result[0] << ", Missing number: " << result[1] << endl;
        }
    }
    return 0;
}
