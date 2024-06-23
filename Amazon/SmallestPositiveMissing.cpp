/*
Examples:

Enter the size of the array: 5
Enter 5 elements of the array: 0 -10 1 3 -20
The smallest positive missing number is: 2

Enter the size of the array: 5
Enter 5 elements of the array: 1 2 3 4 5
The smallest positive missing number is: 6

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingNumber(int arr[], int n)
    {
        for (int i = 0; i < n; ++i)
        {
            if (arr[i] <= 0 || arr[i] > n)
            {
                arr[i] = n + 1;
            }
        }

        for (int i = 0; i < n; ++i)
        {
            int index = abs(arr[i]) - 1;
            if (index >= 0 && index < n && arr[index] > 0)
            {
                arr[index] = -arr[index];
            }
        }

        for (int i = 0; i < n; ++i)
        {
            if (arr[i] > 0)
            {
                return i + 1;
            }
        }

        return n + 1;
    }
};

int main()
{
    Solution solution;
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int missingNumber = solution.missingNumber(arr, n);

    cout << "The smallest positive missing number is: " << missingNumber << endl;

    return 0;
}
