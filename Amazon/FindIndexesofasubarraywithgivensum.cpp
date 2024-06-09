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
