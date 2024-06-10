/*Example 1:
============
Input: arr[] = {1,2,3,7,5}, n = 5, s = 12
Output: 2 4
Explanation: The sum of elements from 2nd to 4th position is 12.

Example 2:
============
Input: arr[] = {1,2,3,4,5,6,7,8,9,10}, n = 10, s = 15,
Output: 1 5
Explanation: The sum of elements from 1st to 5th position is 15.
*/

#include <bits/stdc++.h>
using namespace std;

std::pair<int, int> findSubarrayIndexes(const std::vector<int> &arr, int targetSum)
{
    int n = arr.size();
    int start = 0, end = 0;
    int currentSum = 0;

    while (end < n)
    {
        currentSum += arr[end];

        while (currentSum > targetSum && start <= end)
        {
            currentSum -= arr[start];
            start++;
        }

        if (currentSum == targetSum)
        {
            return std::make_pair(start, end);
        }

        end++;
    }

    return std::make_pair(-1, -1);
}

int main()
{
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    int targetSum;
    std::cout << "Enter the target sum: ";
    std::cin >> targetSum;

    std::pair<int, int> indexes = findSubarrayIndexes(arr, targetSum);

    if (indexes.first != -1 && indexes.second != -1)
    {
        std::cout << "Subarray found from index " << indexes.first << " to " << indexes.second << std::endl;
    }
    else
    {
        std::cout << "Subarray not found." << std::endl;
    }

    return 0;
}
