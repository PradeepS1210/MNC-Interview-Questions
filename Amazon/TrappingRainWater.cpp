/*
Examples:
===========
Enter the number of test cases: 2

Enter the size of the array: 6
Enter the elements of the array: 3 0 0 2 0 4
Water trapped: 10 units

Enter the size of the array: 4
Enter the elements of the array: 7 4 0 9
Water trapped: 10 units

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long trappingWater(int arr[], int n)
    {
        if (n <= 2)
            return 0;

        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        long long waterTrapped = 0;

        while (left <= right)
        {
            if (arr[left] <= arr[right])
            {
                if (arr[left] >= leftMax)
                    leftMax = arr[left];
                else
                    waterTrapped += leftMax - arr[left];
                left++;
            }
            else
            {
                if (arr[right] >= rightMax)
                    rightMax = arr[right];
                else
                    waterTrapped += rightMax - arr[right];
                right--;
            }
        }

        return waterTrapped;
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

        int arr[n];
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution obj;
        long long result = obj.trappingWater(arr, n);
        cout << "Water trapped: " << result << " units\n";
    }

    return 0;
}
