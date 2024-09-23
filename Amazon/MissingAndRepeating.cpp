/*
Example:
=========
Input:
Enter the size of the array: 2
Enter the elements of the array: 2 2

Output:
Repeating number: 2
Missing number: 1

Explanation: Repeating number is 2 and smallest positive missing number is 1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {
        int n = arr.size();

        long long sum_expected = (n * (n + 1LL)) / 2;
        long long sumOfSquares_expected = (n * (n + 1LL) * (2 * n + 1LL)) / 6;

        long long sum_actual = 0;
        long long sumOfSquares_actual = 0;

        for (int i = 0; i < n; i++)
        {
            sum_actual += arr[i];
            sumOfSquares_actual += (long long)arr[i] * arr[i];
        }

        long long sum_diff = sum_expected - sum_actual;
        long long sumOfSquares_diff = sumOfSquares_expected - sumOfSquares_actual;

        long long sum_plus = sumOfSquares_diff / sum_diff;

        int x = (sum_diff + sum_plus) / 2;
        int y = sum_plus - x;

        return {y, x};
    }
};

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution solution;
    vector<int> result = solution.findTwoElement(arr);

    cout << "Repeating number: " << result[0] << endl;
    cout << "Missing number: " << result[1] << endl;

    return 0;
}
