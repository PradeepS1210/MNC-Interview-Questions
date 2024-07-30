/*
Example 1:
===========
Input:
Enter number of elements in the array: 5
Enter the elements of the array: 3 2 4 6 5

Output: Yes
Explanation: a=3, b=4, and c=5 forms a pythagorean triplet.

Example 2:
===========
Input:
Enter number of elements in the array: 3
Enter the elements of the array: 3 8 5

Output: No
Explanation: No such triplet possible.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkTriplet(int arr[], int n)
    {
        unordered_set<int> squares;
        for (int i = 0; i < n; i++)
        {
            squares.insert(arr[i] * arr[i]);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int sumOfSquares = arr[i] * arr[i] + arr[j] * arr[j];
                if (squares.find(sumOfSquares) != squares.end())
                {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    int n;
    cout << "Enter number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution sol;
    bool result = sol.checkTriplet(arr, n);

    if (result)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
