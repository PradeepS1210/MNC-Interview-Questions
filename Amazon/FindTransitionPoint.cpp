/*
Example 1:
============
Input:
Enter the number of elements: 5
Enter the elements (0s and 1s) in sorted order: 0 0 0 1 1

Output: Transition point is at index: 3
Explanation: index 3 is the transition point where 1 begins.

Example 2:
============
Input:
Enter the number of elements: 4
Enter the elements (0s and 1s) in sorted order: 0 0 0 0

Output: No transition point found (no 1 in the array).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int transitionPoint(int arr[], int n)
    {
        if (arr[n - 1] == 0)
        {
            return -1;
        }

        if (arr[0] == 1)
        {
            return 0;
        }

        int low = 0;
        int high = n - 1;
        int transition_point = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] == 1)
            {
                transition_point = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return transition_point;
    }
};

int main()
{
    int N;
    std::cout << "Enter the number of elements: ";
    std::cin >> N;

    int arr[N];
    std::cout << "Enter the elements (0s and 1s) in sorted order: ";
    for (int i = 0; i < N; ++i)
    {
        std::cin >> arr[i];
    }

    Solution sol;
    int result = sol.transitionPoint(arr, N);

    if (result == -1)
    {
        std::cout << "No transition point found (no 1 in the array)." << std::endl;
    }
    else
    {
        std::cout << "Transition point is at index: " << result << std::endl;
    }

    return 0;
}
