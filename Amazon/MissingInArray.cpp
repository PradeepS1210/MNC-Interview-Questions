/*
Example:
==========
Input:
Enter the value of n: 5
Enter 4 elements: 1 2 3 5

Output: The missing number is: 4
Explanation : All the numbers from 1 to 5 are present except 4.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingNumber(int n, vector<int> &arr)
    {
        int totalSum = n * (n + 1) / 2;

        int arraySum = 0;
        for (int num : arr)
        {
            arraySum += num;
        }

        return totalSum - arraySum;
    }
};

int main()
{
    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    vector<int> arr(n - 1);
    cout << "Enter " << n - 1 << " elements: ";
    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
    }

    Solution sol;
    int missing = sol.missingNumber(n, arr);

    cout << "The missing number is: " << missing << endl;

    return 0;
}
